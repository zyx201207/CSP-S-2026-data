#include<bits/stdc++.h>
using namespace std;
struct s{
	int num;
	char c;
};
s a[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	long long sum=0;
	int i=1,j=n;
	
	while(i<j){
		if(a[i].c==a[j].c){
			if(a[i].num>a[j].num){
				a[i].num-=a[j].num;
				j--;
				a[j].num = a[j].num; a[j].c = a[j].c;
			}
			else if(a[i].num<a[j].num){
				a[j].num-=a[i].num;
				i++;
				a[i].num = a[i].num; a[i].c = a[i].c;
			}
			else{
				a[i].num=a[j].num=0;
				i++;j--;
				a[j].num = a[j].num; a[j].c = a[j].c;
				a[i].num = a[i].num; a[i].c = a[i].c;
			}
		}
		else{
			sum+=min(a[i].num,a[j].num);
			if(a[i].num>a[j].num){
				a[i].num-=a[j].num;
				j--;
				a[j].num = a[j].num; a[j].c = a[j].c;
			}
			else if(a[i].num<a[j].num){
				a[j].num-=a[i].num;
				i++;
				a[i].num = a[i].num; a[i].c = a[i].c;
			}
			else{
				a[i].num=a[j].num=0;
				i++;j--;
				a[j].num = a[j].num; a[j].c = a[j].c;
				a[i].num = a[i].num; a[i].c = a[i].c;
			}
		}
	}
	cout<<sum;
	return 0;
}
