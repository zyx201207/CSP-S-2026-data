//GZ-J00690   öÄ²Åº­ 
#include <bits/stdc++.h>
using namespace std;

int an(int x,int y)

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	int n,m,a[10000]={0},max=INT_MIN;
	
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((a[i]&a[j])>max){
				max=a[i]&a[j];
			}
		}
	}
		
	printf("%d",max);	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
