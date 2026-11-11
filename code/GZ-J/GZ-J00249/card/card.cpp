#include<bits/stdc++.h>
using namespace std;
int main(){
	//准考证号:GZ-J00249 姓名:王锴碹
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int> a(n + 1,0);
	vector<int> record(m + 1,0);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	for(int i = 1;i <= n;i++){
		vector<int> b = a;
		vector<int> vis(m + 1,0);
		vector<int> fir(m + 1,-1);
		for(int j = i;j <= n;j++){
			if(b[j] == -1) continue;
			if(fir[b[j]] == -1) fir[b[j]] = j;
			vis[b[j]]++;
			if(vis[b[j]] == 2){
				for(int k = fir[b[j]];k < j;k++){
					b[k] = -1;
					fir[k] = -1;
				}
			}
		}
		for(int j = i;j <= n;j++){
			if(b[j] != -1){
				record[b[j]]++;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		printf("%d ",record[i]);
	}
	return 0;
}

