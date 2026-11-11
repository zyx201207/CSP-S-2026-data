//GZ-J00495 六盘水知见外国语学校 蔡昕清
#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n,a[1005],b[1005];
	cin>>n>>m;
	int d;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int j=0;j<m;j++){
		int q;
		d=a[0];
		for(int i=0;i<n;i++){
			if (d<=a[i]){
				q=i;
				d=max(d,a[i]);	
			}
		}
		a[q]=0;
		b[j]=d;
	}
	int count=b[0];
	for(int i=0;i<m;i++){
		count=count&b[i];
	}
	cout<<count;
	return 0;
}
