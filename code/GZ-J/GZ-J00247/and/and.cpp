//GZ-J00247，秦泽锦玥，安顺开发区长水大洋实验学校 
#include<bits/stdc++.h>
using namespace std;
long long m,a[2000005],l; 
int  n;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	int b=a[n-1]%a[n];
	int k=1;
	if(m>2){
		for(int i=1;i<m-1;i++){
			l=b;
			b=a[n-1-k]%l;
			k++;
	}
	}
	 cout<<b;
	return 0; 
}
//5 3 31 3 1 15 7 排序1 3 7 15 31 
