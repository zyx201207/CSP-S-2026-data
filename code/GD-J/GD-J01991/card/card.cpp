#include<bits/stdc++.h>
using namespace std;
int n,m,w1,w2;
int a[500005],cnt[500005],ans[500005];
	

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m==1){
		cout << n;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cnt[j]=0;
		}
		for(int j = i;j <= n;j++){
			if(cnt[a[j]]){
				for(int k = cnt[a[j]];k < j;k++){
					cnt[a[k]]=0;
				}
				cnt[a[j]]=j;
			}
			else cnt[a[j]]=j;
			//cout << a[j] << ":" << cnt[a[j]]<<"\n";
		}
		for(int j = 1;j <= m;j++){
			if(cnt[j])ans[j]++;
			//cout << ans[j] << " ";
		}
		
		//cout << "\n";
	}
	for(int i = 1;i <= m;i++)cout << ans[i] << " ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}



