#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,num,len,ans,tmp;
int a[200010];
int vis[200010];
bool flag;
vector <int> place[100];
void work(int i){
	int step=a[i],k=0;
	while(step!=0){
		if(step%2==1){
			place[k].push_back(i);
		}
		k++;
		step/=2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		work(i);
	}
	for(int i=35;i>=0;i--){
		if(place[i].size()<m){
			continue;
		}else{
			cnt++;
			num=0;
			len=place[i].size();
			for(int j=0;j<len;j++){
				vis[place[i][j]]++;
			}
			flag=true;
			for(int j=1;j<=n;j++){
				if(vis[j]==cnt){
					num++;
					if(flag){
						tmp=a[j];
						flag=false;
					}else{
						tmp&=a[j];
					}
				}
			}
			if(num<m){
				break;
			}
			ans=max(ans,tmp);
		}
	}
	printf("%d",ans);
	return 0;
} 
