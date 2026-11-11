//GZ-J00187  遵义市新蒲中学 王墨霖 
#include <bits/stdc++.h>
using namespace std;
int a[500005],a1[300005],b[500005],q;
int fround(int h,int w,int a3){
	for(int e=h;e<=w;e++){
		if(b[e]==a3){
			return e;
		}
	}
	return 0;
}
bool cop(int x,int y){
	return x>y;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int p=1;p<=n;p++){
		for(int i=p;i<=n;i++){
			int b1=fround(1,q,a[i]);
			if(b1>0){
				q=b1;
			}else{
				q++;
				b[q]=a[i];
			}
		}
		sort(b+1,b+q+1,cop);
		for(int i=1;i<=q;i++){
			if(b[i]!=b[i-1]) a1[b[i]]++;
		}
		for(int i=0;i<=q;i++){
			b[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a1[i]<<" ";
	}
	return 0;
}

