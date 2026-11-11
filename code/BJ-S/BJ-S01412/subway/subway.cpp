#include<bits/stdc++.h>
using namespace std;
int s[501][501];
void bl();
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	for(int i=0;i<501;i++)
		for(int j=0;j<501;j++)
			s[i][j]=20000000;
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    if(c==20||c==21){
    int w[m];
    int t[m],tt[m];
    for(int i=0;i<m;i++)cin>>w[i];
    int k,ans=1000000000;
	cin>>k;
	for(int j=0;j<k;j++){
		int x,y;
		cin>>x>>y;
		t[x]=y;
	}
	cin>>k;
	for(int j=0;j<k;j++){
		int x,y;
		cin>>x>>y;
		tt[x]=y;
		if(t[x]!=0)ans=min(ans,t[x]+y);
	}
	//cout<<ans;
	while(q--){
		
		int l,r;
		cin>>l>>r;
		int eee=0;
		if(t[l]!=0&&tt[l]==0)eee+=t[l];
		if(t[l]==0&&tt[l]!=0)eee+=tt[l];
		if(t[r]!=0&&tt[r]==0)eee+=t[r];
		if(t[r]==0&&tt[r]!=0)eee+=tt[r];
		if(t[l]!=0&&tt[l]!=0&&t[r]!=0)eee+=t[l];
		if(t[l]!=0&&tt[l]!=0&&tt[r]!=0)eee+=tt[l];
		if(t[r]!=0&&tt[r]!=0&&t[l]!=0)eee+=t[r];
		if(t[r]!=0&&tt[r]!=0&&tt[l]!=0)eee+=tt[r];
		if(!((t[l]!=0&&t[r]!=0))||((tt[l]!=0&&tt[r]!=0)))eee+=ans;
		cout<<w[l-1]+w[r-1]+eee<<endl;}
	/*while(q--){
		int l,r;
		cin>>l>>r;
		for(int i=0;i<n;i++){
			if(t[i][l]!=0){
				
				
				
				
			}
		}
		
		
		
		
	}*/
}
    return 0;
}

