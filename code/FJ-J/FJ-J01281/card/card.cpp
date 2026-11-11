#include<bits/stdc++.h>
using namespace std;
int n,m,arr[500005],s[500005],t[500005],qj[500005],zps[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(!s[arr[i]]){
			s[arr[i]]=i;
		}
		else{
			t[s[arr[i]]]+=s[arr[i]];
			t[i]-=s[arr[i]];
			s[arr[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		qj[i]=qj[i-1]+t[i];
	}
	for(int i=1;i<=n;i++){
		zps[arr[i]]=max(zps[arr[i]],i-qj[i]);
	}
	for(int i=1;i<=m;i++){
		cout<<zps[i]<<" ";
	}
	return 0;
}
