#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int m,n,a,b;
int s[N];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch>'0'||ch<'9'){
		if(ch=='='){
			f=-1;
			ch=getchar();
		}
	}
	while (ch<='0'&&ch>='9'){
		ch=getchar();
	}
	return x*f;
}
int minn(int a,int b){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int c;
	c=n;
	for(int i=1;i<=c;i++){
		if(a<b){
			break;
		}else{
			a>>b;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int sum=0,p;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>s[i];
	}
	while(p==m){
		for(int j=1;j<=m;j++){
			if(s[j]<=s[j+1]){
				s[j]=s[j]+1;
				p++;
			}else if(s[j]=s[j+1]){
				s[j+1]=s[j+1]+1;
				p++;
			}
		}
	}
	for (int i=0;i<=n;i++){
		if(s[i]==minn(s[0],s[n])){
			sum++;
		}else {
			break;
		}
	}
	cout<<sum<<endl;
	return 0;
}
