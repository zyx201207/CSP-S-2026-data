#include<bits/stdc++.h>
using namespace std;
const int N=5e5+15;
int n,m;
int table[N],last[N],sum[N],a[N];
int nowpos,tail;
int c11,c22;
int main(){
	freopen("card.out","w",stdout);
	freopen("card.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) c11++;
		if(a[i]==2) c22++;
	}
	if(m==2){
		if(a[n]==1) cout<<n<<" "<<c22;
		else cout<<c11<<" "<<n;
		return 0;
	}
	for(int k=1;k<=n;k++){
		memset(last,0,sizeof last);
		memset(table,0,sizeof table);
		nowpos=0;
		tail=0;
		for(int i=k;i<=n;i++){
			if(last[a[i]]){
				nowpos=last[a[i]];
				for(int i=nowpos+1;i<=tail;i++) last[table[i]]=0;
			}else{
				nowpos++;
				tail=max(tail,nowpos);
				table[nowpos]=a[i];
				last[a[i]]=nowpos;
			}
		}
		for(int i=1;i<=nowpos;i++){
			//cout<<table[i]<<" ";
			sum[table[i]]++;
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	fclose(stdout);
	fclose(stdin);
	//zhe ge jian pan hao nan yong
	return 0;
}
