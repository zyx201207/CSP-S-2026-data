#include<bits/stdc++.h>
using namespace std;
int a[200003],n;
string s;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string l;
		cin>>a[i]>>l;
		s+=l;
	}s="/"+s;
	int q=1,h=n;
	while(q<h){
		bool p=1;
		if(s[q]==s[h])p=0;
		if(a[q]>=a[h]){
			if(p)ans+=a[h];
			a[q]-=a[h];
			a[h]-=a[h];
			//s[h]=s[q];
		}else{
			if(p)ans+=a[q];
			a[h]-=a[q];
			a[q]-=a[q];
			//s[q]=s[h];
		}//cout<<s[q]<<" "<<s[h]<<" "<<ans<<endl;
		if(a[q]==0)q++;
		if(a[h]==0)h--;
	}cout<<ans;
	return 0;
}
