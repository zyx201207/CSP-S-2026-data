//GZ-J00503 ¶ÅÓÀå·
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[5000005];
    int cnt[3000005];
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]){
				i=j;
				break;
			}
			else
			    cnt[i]++;
			
		}
	}
    for(int i=0;i<n;i++){
    	cout<<cnt[i];
	}

return 0;
}
