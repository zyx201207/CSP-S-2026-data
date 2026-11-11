#include<bits/stdc++.h>
using namespace std;
long long n,d,a[2000010],fly[2000010],m[310][310],cnt[310][310],ans;
void init(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
}
int find(int l,int r){
    if(m[l][r]){
		return m[l][r];
	}
	if(r<=fly[l]){
		m[l][r]=1;
		return 1;
	}
	else{
		m[l][r]=find(fly[l],r)+1;
		return m[l][r];
	}
}
int walk(int st,int en){
	for(int i=st+1;i<=fly[st] && i<=n;i++){
		ans=1+walk(i,en);
		if(ans==m[st][en]){
			cnt[st][en]++;
		}	
	}	
}
void func(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				fly[i]=j;
				m[i][j]=1;
			}
			else{
				j=n+1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			find(i,j);
			walk(i,j);
			if(cnt[i][j]==2){
				ans++;
			}
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t){
		t--;
		ans=0;
		init();
		func();
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cnt[i][j]=0; 
			} 
		}
	}
	return 0;
}
