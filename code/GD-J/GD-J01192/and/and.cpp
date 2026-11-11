#include <iostream>
#include <cstdio>
#include <algorithm>

#define N 200005

using namespace std;

int n,m,pow2=1;
int a[N],a2[N][31],s[N];

void ejz(int x){
	int k=a[x],idx=-1;
	while(k){
		a2[x][++idx]=k%2;
		k/=2;
	}
}
bool cmp(int x,int y){
	return x>y;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) ejz(i);
	
	for(int j=0;j<30;j++){
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(a2[i][j]==1)
				cnt++;
		if(cnt>=m){
			for(int i=1;i<=n;i++)
				if(a2[i][j]==1)
					s[i]+=pow2;
		}
		pow2*=2;
	}
	sort(s+1,s+n+1,cmp);
	
	int sum=0;
	pow2/=2;
	for(int j=29;j>=0;j--){
		bool flag=1;
		for(int i=1;i<=m;i++){
			if(s[i]<pow2){
				flag=0;
				break;
			}
		}
		if(flag==1){
			sum+=pow2;
			for(int i=1;i<=m;i++)
				s[i]-=pow2;
		}
		pow2/=2;
	}
	cout<<sum;
	return 0;
} 
