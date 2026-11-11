//GZ-t00611 北京师范大学贵阳附属中学 陆志嘉 
#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int w=n;
	int i=1,j=2,c=2;
	long long cnt=a[i],ant=a[j],ma=0;
	cnt=cnt&a[2];
	ant=ant&a[3];
	while(w--){
		ant=max(ant,cnt);
		if(ant==cnt){
			j=i;
		}
		i++;
		cnt=a[i];
		c++;
		ant=ant&a[j+c];
		for(int k=i+1;k<=i+c;k++){
			cnt=cnt&a[k];
		}
		if(c==m){
			ma=max(ant,ma);
			i=j+1;
			j++;
			c=0;
			cnt=a[i];ant=a[j];
		}
	}
	cout<<ma;
	return 0;
}
