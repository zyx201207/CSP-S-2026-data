#include<bits/stdc++.h>
using namespace std;
int m,n;
string s[200100],se;
bool vis[200100];
long long a[200100],sum=-1;
bool cmp(long long x,long long y){
	return x>y;
}
int wei=0;
long long bt=1073741824;
void tobit(long long x,int id){
	se="";
	for(int i=1;i<=30;i++){
		if(x%2==1) se=se+"1";
		else se=se+"0";
		x/=2;
	}
	for(int i=30;i>=0;i--){
		s[id]+=se[i];
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tobit(a[i],i);
	}
	int cnt=0;
	for(int j=1;j<=30;j++){
		cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==true) continue;
			if(s[i][j]=='1') cnt+=1;
		}
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(s[i][j]!='1') vis[i]=true;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(m==0) break;
		if(vis[i]==false){
			if(sum==-1) sum=a[i];
			else sum=sum&a[i];
			m-=1;
		}
	}
	cout<<sum;
	return 0;
}