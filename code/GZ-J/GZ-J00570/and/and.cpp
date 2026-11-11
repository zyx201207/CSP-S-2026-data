#include<bits/stdc++.h>
using namespace std;
string t_t(int n){
	string x="01";
	string ans="";
	while(n){
		int m=n%2;
		ans=x[m]+ans;
		n/=2;
	}
	return ans;
}
int f(string s){
	int sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]==1){
			sum++;
		}
	}
	return sum;
}
struct box{
	int n;
	int sum;
	int s;
};
bool cmp(box x,box y){
	if(x.sum!=y.sum){
		return x.sum>y.sum;
	}
	else if(x.sum==y.sum){
		return x.s>y.s;
	}
}
int main(){
//	GZ-J00570 遵义市第十二中学  喻思豪 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	box arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i].n;
		string ss=t_t(arr[i].n);
		arr[i].s=ss.size();
		arr[i].sum=f(ss);
	}
	sort(arr+1,arr+n+1,cmp);
	
	int ans=arr[1].n,i=0;
	
	while(m--){
		i++;
		ans=(ans&arr[i].n);
		
	}
	cout<<ans;
//	int n;
//	cin>>n;
//	cout<<t_t(n);
	return 0;
} 
/*
4 2
3 15 12 12
*/
