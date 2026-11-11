#include <bits/stdc++.h>
using namespace std; 
int ans;
int main(void){
        freopen("crystal2.in","r",stdin);
        freopen("crystal2.out","w",stdout);
        int n,m;
        cin>>n>>m;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    	int a=n/2;
    	int f[a];
    	int w=0;
        for(int i=0;i<n;i++){
        	if(arr[i]<arr[a]){
        		f[w]=arr[i];
        		w++;
			}else if(arr[i]==arr[a]){
				ans++;
			}
		}
		int abs=0,x=m;
		for(int i=0;i<w;i++){
			for(int j=0;j<n;j++){
				abs=max(f[j],f[j+1]);
				if(f[j]==abs){
					f[j]=0;
				}else if(f[j+1]==abs){
					f[j+1]=0;
				}
			}
			if(x-abs>=0){
				x-=abs;
				ans++;
			}
			abs=0;
		}
		cout<<ans<<endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
}
