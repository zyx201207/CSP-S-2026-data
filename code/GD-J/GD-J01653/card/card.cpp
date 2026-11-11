#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1,c=0;
long long a[20005],b[20005],t[20005],tt[20005];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=1;
		for(int j=i;j<=20000;j++){
			b[j]=0;
			t[j]=0;
		}
		for(int j=i;j<=n;j++){
			b[cnt++]=a[j];
			if(t[a[j]]==1){
				for(int k=1;k<=cnt-2;k++){
					b[k]=0;
				}
				for(int k=1;k<=n;k++){
					b[k]=0;
				}
				int j=a[j];
				b[cnt-1]=0;
				b[1]=j;
				cnt=2;
				t[a[j]]=0;
			}else{
				t[a[j]]=1;
			}
		}
		for(int j=1;j<=3000;j++){
			if(t[j]==1){
				tt[j]+=1;
				t[j]=0;
				cout << "tt[" << j << "]:" << tt[j] << endl;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout << tt[i] << " ";
	}
	return 0;
}
