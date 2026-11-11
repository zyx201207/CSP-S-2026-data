#include<bits/stdc++.h>
using namespace std;
int  a[210000],n,cnt=0,ans=0;
char c[210000];
vector<int>v,t;
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n-1;i++){
	    cin>>a[i];
		cin>>c[i]; 
		for(int j=0;j<=a[i]-1;j++){
			v.push_back(0);
			v[j]=c[i];
	        cnt++;
	    }
	}
	for(int i=0;i<=cnt-1;i++){
		t.push_back(0);
	}
	for(int i=cnt-1;i>=0;i--){
		for(int j=1;j<=cnt;j++){
			t[j]=v[i];
		}
	}
	if(cnt%2==1){
		cnt++;
	}
	for(int i=0;i<=cnt/2-1;i++){
		if(v[i]!=t[i]){ans++;}
	}
	cout<<ans;
	return 0;
}
