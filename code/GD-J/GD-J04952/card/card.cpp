#include <bits/stdc++.h>
using namespace std;

const int N=5*1000*100+10,M=3*1000*100+10;

int a[N],b[M];
int cnt[M];
int q[N],qlen=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	

	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	

	
	int n,m;
	cin >>n>>m;
	
	for (int i=1;i<=n;i++)cin >>a[i];
	

	
	for (int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		
		for (int j=i;j<=n;j++){


			if (b[a[j]]!=0){
				int p=b[a[j]];
			
				while (qlen!=0&&p<=q[qlen]){
					b[a[q[qlen]]]=0;
					qlen--;
				}

			}
			
			b[a[j]]=j;
			qlen++;
			q[qlen]=j;

		}
		
		while (qlen!=0){
//			cout <<a[q[qlen]]<<' ';
			cnt[a[q[qlen]]]++;
			qlen--;
		
		}
//		cout <<endl;

	}
	
	for (int i=1;i<=m;i++)cout <<cnt[i]<<' ';
	
	return 0;
}
