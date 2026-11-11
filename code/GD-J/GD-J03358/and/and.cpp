#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[200005],b[200005];     //数据，下标 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}   //输入 
	
	for(int i=0;i<m;i++){
		b[i]=i;
	}   //下标赋值 
	long long w=a[0];    //与的值 
	long long max=-1;
	while(b[0]!=n-m+1){
		
		for(int j=b[m-1];j<n;j++){  //下标移动 
			b[m-1]=j;
			for(int k=1;k<m;k++){  //与的次数 
				w=(w&a[b[k]]);
				
			}
			if(w>max)max=w;
			w=a[b[0]];
		}

		for(int l=m-1;l>=0;l--){
			if(b[l]>=n-1){
				b[l-1]++;
				b[l]=b[l-1]+1;
			}
		}
		if(b[m-1]>n-1)b[m-1]=b[m-2]+1;
	}
	cout<<w;
	
	return 0;
}
