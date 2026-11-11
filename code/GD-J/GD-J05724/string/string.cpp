#include<bits/stdc++.h>
using namespace std;
int n;
struct p{
	int x;
	string a;
}s[200001];
long long x,sum=0,ii=0,jj=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].x>>s[i].a;
		jj++;
	}
	while(1){
		if(ii>=jj){
			break;
		}
		int q=s[ii].x,w=s[jj].x;
		if(q==0) ii++;
		if(w==0) jj--;
		int mn=min(q,w);
		if(s[ii].a!=s[jj].a){
			sum+=mn;
			s[ii].x-=mn;
			s[jj].x-=mn;
		}else{
			s[ii].x-=mn;
			s[jj].x-=mn;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
