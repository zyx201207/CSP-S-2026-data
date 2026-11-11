#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m;
struct edge{
	int a;
	char b;
};
edge c[N];
bool flag1=1,flag2,flag3;
long long ans;
int x,y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].a>>c[i].b;
		m+=c[i].a;
	}
	int mid=n/2;
	for(int i=1;i<=mid;i++){
		if(c[i].a!=c[n-i].a||c[i].b!=c[n-i].b){
			flag1=0;
		}
		if(c[i].a!=c[n+1-i].a){
			flag3=1;
		}
	}
	if(flag1){
		cout<<0;
		return 0;
	}
	if(flag3==0){
		for(int i=1;i<=n/2;i++){
			ans+=c[i].a;
		}
		cout<<ans;
		return 0;
	}
	int qian=c[1].a,hou=c[n].a;
	for(int i=1;i<=n-1;i++){
		if(c[i].a!=c[i+1].a){
			flag2=1;
		}
	}
	if(flag2){
		for(int i=1;i<=n/2;i++){
			x+=c[i].a;
			y+=c[n+1-i].a;
		}
		if(x==y){
			cout<<x;
			return 0;
		}
		for(int i=1;i<=n;i++){

			if(qian>hou&&c[i].b!=c[n+1-i].b&&ans<hou){
			ans=hou;
			hou+=c[n-i].a;
		}else if(qian>hou&&c[i].b!=c[n+1-i].b&&ans>=hou){
			hou+=c[n-i].a;
		}else if(qian<hou&&c[i].b!=c[n+1-i].b&&ans<qian){
			ans=qian;
			qian+=c[i+1].a;
		}else if(qian<hou&&c[i].b!=c[n+1-i].b&&ans>=qian){
			qian+=c[i+1].a;
		}else if(qian==hou&&c[i].b!=c[n+1-i].b){
			ans+=c[n+1-i].a;
			qian+=c[i+1].a;
			hou+=c[n-1].a;
			flag3=1;
		}
	}
	if(qian==hou){
		cout<<qian;
		return 0;
	}
	}else{
		for(int i=1;i<=n/2;i++){

			if(qian>hou&&c[i].b!=c[n+1-i].b){
			ans+=c[n+1-i].a;
			hou+=c[n-i].a;
		}else if(qian<hou&&c[i].b!=c[n+1-i].b){
			ans+=c[i].a;
			qian+=c[i+1].a;
		}else if(qian==hou&&c[i].b!=c[n+1-i].b){
			ans+=c[n+1-i].a;
			qian+=c[i+1].a;
			hou+=c[n-1].a;
		}
		
	}
	}

		
		
	
	cout<<ans;
	
	return 0;
}
