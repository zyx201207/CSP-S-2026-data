#include <bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+10;
struct node{
	int cnt;
	char n;
}p[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout)
	cin>>n;
	int cnt1=0;
	for(int i=1;i<=n;i++){
		cin>>p[i].cnt>>p[i].n;
		cnt1+=p[i].cnt;	
	}
	string s;
	int k=1;
	bool flag=0;
	for(int i=1;i<n;i++){
		for(int j=1;j<=p[i].cnt;j++){
			s[k]=p[i].n;
			k++;
		}
	}
	for(int i=1;i<=n;i++){
		if(p[i].n!=p[i+1].n)flag=1;
	}
	if(flag==0){
		cout<<0<<endl;
	}else{
		int l=1,r=k,ans=0;
		while(true){
			if(s[l]!=s[r]){
				ans++;		
			}
			l++;
			r--;
			if(l==r-1&&cnt1%2==0){
				break;
			}else if(l==r&&cnt1%2==1){
				break;
			}
		}	
		cout<<ans<<endl;
	}
	
	return 0;
}
