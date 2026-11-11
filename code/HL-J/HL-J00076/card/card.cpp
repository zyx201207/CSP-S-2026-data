#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    //vector<int> a;
    int n,m,count=0,s=0;
    cin >> n >> m;
    int ans=n/m;
    int a[n];
    for(int i=0;i<m;i++){
    	cin >> a[i];
    }
    //for(int i=0;i<m;i++){
    //	card[i]=a[i];
    	//tong[a[i]]++;
    //	count++;
    	//if(//tong[a[i]]>1){
    	//	for(int j=sign[a[i]]+1;j<=count;j++){
    	//		card[j]=0;
    	//		i=j;
    	//		n--;
    	//	}
    	//sign[a[i]]=i;
    	//}
    //	for(int j=1;j<=n;j++){
    //		if(card[j]);
    //	}
   // }
    cout << n << " ";
    for(int i=0;i<m-1;i++){
        cout << ans<<" ";
    }
    return 0;
}
