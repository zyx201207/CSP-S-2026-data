#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n],c[m];
    memset(c,0,sizeof(c));
    for(int i = 0;i < n;i++){
    	cin >> a[i];
	}
    for(int i = 0;i < n;i++){
    	int y[n],cnt = 0;
    	for(int j = i;j < n;i++){
    		bool s = true;
    		int b;
    		for(int k = 0;k < cnt;k++){
    			if(a[j] == y[k]){
    				s = false;
    				b = k;
				}
			}
			if(s){
				cnt++;
				y[cnt] = a[j];
			}else{
				int ans = 0;
				for(int k = b;k < cnt;k++){
					ans++;
					y[k] = 0;
				}
				cnt-=ans;
				cnt++;
				y[cnt] = a[j];
			}
		}
		for(int k = 0;k < cnt;k++){
			c[y[k]]+=1;
		}
	}
	for(int i = 0;i < n;i++){
		if(c[i]!=0){
			cout << c[i] << ' ';
		}
	}
	return 0;
} 
