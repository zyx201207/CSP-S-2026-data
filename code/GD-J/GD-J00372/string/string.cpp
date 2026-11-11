#include<bits/stdc++.h>
using namespace std;
struct c{
	int num;
	char a;
};
vector<c>ch;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	ch.resize(n);
	long long sum=0;
	long long ans=0;
	for(int i=0;i<n;i++){
		cin>>ch[i].num>>ch[i].a;
		sum+=(long long)ch[i].num;
	}
	sum-=sum%2;
	sum/=2;
	int l=0;
	int r=n-1;
	while(sum){
		if(ch[l].a!=ch[r].a){
			if(ch[l].num>ch[r].num){
				if(sum<=ch[r].num){
					ans+=sum;
					break;
				}
				ans+=ch[r].num;
				sum-=ch[r].num;
				ch[l].num-=ch[r].num;	
				r--;
			}else if(ch[l].num<ch[r].num){
				if(sum<=ch[l].num){
					ans+=sum;
					break;
				}
				sum-=ch[l].num;
				ans+=ch[l].num;
				ch[r].num-=ch[l].num;
				l++;
			}else{
				if(sum<=ch[r].num){
					ans+=sum;
					break;
				}
				ans+=ch[r].num;
				sum-=ch[r].num;
				r--;
				l++;
			}
		}else{
			if(ch[l].num>ch[r].num){
				if(sum<=ch[r].num){
					break;
				}
				sum-=ch[r].num;
				ch[l].num-=ch[r].num;	
				r--;
			}else if(ch[l].num<ch[r].num){
				if(sum<=ch[l].num){
					break;
				}
				sum-=ch[l].num;
				ch[r].num-=ch[l].num;
				l++;
			}else{
				if(sum<=ch[r].num){
					break;
				}
				sum-=ch[l].num;
				r--;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
