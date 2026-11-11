#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<char,ll>mp;
const int N=2e5+5;
int a[N];
char c[N];
ll sum,l,s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
		s[i]=s[i-1]+a[i];
	}int id;
	for(int i=1;i<=n;i++){
		if(l/2<=s[i]){
			id=i;
			break;
		}
	}
	if(s[id]==l/2){
		for(int i=1;i<=id;i++){
			mp[c[i]]+=a[i];
			//cout<<a[i]<<" "<<mp[c[i]]<<endl;
		}
		for(int i=id+1;i<=n;i++){
			mp[c[i]]-=a[i];
			if(mp[c[i]]<0) mp[c[i]]=0;	
		}
		for(int i=1;i<=id;i++){
			if(c[i]!=c[i-1]) sum+=mp[c[i]];		
		}
		cout<<sum;
	}else{
		for(int i=1;i<id;i++){
			mp[c[i]]+=a[i];
		}
		mp[c[id]]+=s[id]-l/2;
		if(mp[c[id]]<0) mp[c[id]]=0;
		for(int i=id+1;i<=n;i++){
			mp[c[i]]-=a[i];
			if(mp[c[i]]<0) mp[c[i]]=0;	
		}		
		for(int i=1;i<=id;i++){
			if(c[i]!=c[i-1]) sum+=mp[c[i]];		
		}
		cout<<sum;		
	}
	return 0;
}
