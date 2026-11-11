#include<bits/stdc++.h>
using namespace std;
string s[100005];
char c[100005];
long long int y,sum,mid,midn,len,n,a[100005];
int hwc(string s1){
	int i=0,j=len;
	while(i<j){
		if(c[i]!=c[j]) return 0;
		else i+=1,j-=1;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	mid=(len+1)/2;
//	for(int i=1;i<=n;i++){
//		if(mid=mid-a[i]<=0) midn=i;
//	}
//	int i=1,l=n;
//	while(i<=l){
//		if(c[i]!=c[l]){
//			y=a[l]-a[i];
//			if(y<0){
//				while(y<0){
//					l-=1;
//					y=a[l]+y;
//					if(y>0){
//						i+=1;
//						break;
//					}
//				}
//			}else{
//				i+=1;
//				while(y>0){
//					y=y-a[i];
//					if(y<0){
//						j-=1;
//						break;
//					}
//				}	
//			}
//		}
//	}
	int j=1;
	for(int i=1;i<=n;i++){
		for(int i1=1;i1<=a[i];i1++) s[j++]=c[i];
	}
	int i=1,l=len;
	while(i<=l){
		if(s[i]!=s[l]) sum++;
		i+=1,l-=1;
	}
	cout<<sum<<endl;
	return 0;
}
