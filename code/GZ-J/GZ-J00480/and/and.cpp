//GZ-J00480 赵浩钦 遵义航天高级中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	int max1=-1e9;
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(a[i]&a[j]>max1){
				max1=a[i]&a[j];
			}
			
		}
	}cout<<max1;
//    fclose(stdin);
//    fclose(stdout);
	return 0;
}

