#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char a;
}init[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>init[i].num>>init[i].a;
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		if(init[l].num==init[r].num){
			if(init[l].a!=init[r].a){
				ans+=init[l].num;
			}
			l++;
			r--;
		}
		else if(init[l].num<init[r].num){
			if(init[l].a!=init[r].a){
				ans+=init[l].num;
			}
			init[r].num-=init[l].num;
			l++;
		}
		else{
			if(init[l].a!=init[r].a){
				ans+=init[r].num;
			}
			init[l].num-=init[r].num;
			r--;
		}
	}
	cout<<ans;
	return 0;
}

