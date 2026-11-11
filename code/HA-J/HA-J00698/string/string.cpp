#include<bits/stdc++.h>
using namespace std;
struct stringzip{
	long long longth;
	char zifu;
}sz[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long xchar=0;
	cin>>n;
	long long right=0;
	for(int i=1,j=1;i<=n;i++){
		scanf("%d",&sz[i].longth);
		cin>>sz[i].zifu;
		right+=sz[i].longth;
//		stringzip a;
//		scanf("%d",&a.longth);
//		cin>>a.zifu;
//		right+=a.longth;
//		if(i==1 || a.zifu!=sz[i].zifu){
//			j++;
//			sz[j].zifu=a.zifu;
//			sz[j].longth=a.longth;
//		}
//		else{
//			sz[j].longth+=a.longth;
//		}
	}
	long long l=1,r=right;
	for(int i=1,j=n;i<j;){
		if(sz[i].zifu!=sz[j].zifu){
			if(sz[i].longth>sz[j].longth){
				sz[i].longth-=sz[j].longth;
				j--;
				l+=sz[j].longth;
				r-=sz[j].longth;
				xchar=sz[j].longth;
			}
			else if(sz[i].longth<sz[j].longth){
				sz[j].longth-=sz[i].longth;
				i++;
				l+=sz[i].longth;
				r-=sz[i].longth;
				xchar=sz[i].longth;
			}
			else{
				i++;
				j--;
				l+=sz[j].longth;
				r-=sz[j].longth;
				xchar=sz[j].longth;
			}
		}
	}
	cout<<xchar;
	return 0;
}
