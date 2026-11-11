//GZ-J00063 毕节七星关东辰实验学校 吴拼 
#include<iostream>
#include<string>
using namespace std;
int num[500005];
int times[300005]={},appear[300005]={},has[300005]={};
bool place[300005];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>num[i];
	}
	for(int i=n;i>=1;i--){
		appear[num[i]]++;
		if(appear[num[i]]>=2){
			place[i]=true;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(has[num[i]]!=0){
			for(int j=has[num[i]];j<i;j++){
				times[num[j]]--;
			}
			has[num[i]]=0;
		}else{
			has[num[i]]=i;
			times[num[i]]++;
		}
	}
	int cnt=0;
	for(int i=2;i<=n;i++){
		if(place[i-1]=true){
			for(int j=i;j<=n ; j++){
				times[num[j]]+=cnt;
				if(num[j]=num[i-1]){
					break;
				}
				
			}
		}
		cnt++;
	}
	times[m]=n;
	for(int i=1;i<=m;i++){
		printf("%d ",times[i]);
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	fclose(stdout);
	return 0;
}

