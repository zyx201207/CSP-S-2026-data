#include<bits/stdc++.h>
using namespace std;
const int MAXN=200010;
int choose[MAXN];
int num[MAXN];
int n,m,ans;
int main(){
	freopen("and.in","r",stdin);
	//freopen("E:\\cspj\\down\\and\\and4.in","r",stdin);
	
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>num[i];
		choose[i]=i;
	}
	
	ans=0xffffffff;
	for(int i=1;i<=m;i++){
		ans&=num[choose[i]];
	}
	while(true){
		int k=m;
		while(k>0&&choose[k]==n-m+k) k--;
		if(k==0) break;
		choose[k]++;
		for(int i=k+1;i<=m;i++){
			choose[i]=choose[k]+(i-k);
		}
		int cnt=0xffffffff;
		for(int i=1;i<=m;i++){
			cnt&=num[choose[i]];
		}
		ans=max(ans,cnt);
	}
	
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}



