#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],b[300010],jg[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> zm;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				zm.push_back(a[j]);
				b[a[j]]++;
			}else{
				for(int c=0;c<zm.size();c++){
					if(zm[c]==a[j]){
						for(int k=c;k<zm.size();k++){
							zm.erase(zm.begin()+k,zm.begin()+k);
							b[zm[k]]--;
						}
					}
				}
				zm.push_back(a[j]);
			}
		}
		for(int c=0;c<zm.size();c++){
			jg[zm[c]]++;
		}
        memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++){
		cout<<jg[i]<<' ';
	}
	return 0;
}
