#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[300005],ans[300005],z,y,sw[300005],xx[500005],s;
bool f=1;
int main(){
	freopen("card.in","r","stdin");
	freopen("card.out","w","stdout");
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;	
	for(int i=1;i<=n;i++){
		cin >> a[i];
		t[a[i]]++;
		if(i>2){
			if(a[i]<a[i-1]){
				f=0;
			}
		}
	}
	if(f==1){
		for(int i=1;i<=m;i++){
			t[i]+=t[i-1];
			cout << t[i] << " ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(sw,-1,sizeof(sw));
		xx[i-1]=i;
		for(int j=i;j<=n;j++){
			xx[j]=j+1;
			if(sw[a[j]]!=-1){
				for(int k=sw[a[j]]-1;k<=j-1;k++){
					xx[k]=j;
				}
				
			}
			sw[a[j]]=j; 
		}
		s=xx[i-1];
		while(s<=n && s>0){
			//cout << s << " ";
			ans[a[s]]++;
			s=xx[s];
		}
		//cout << endl;
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
