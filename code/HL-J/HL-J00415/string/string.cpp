#include <bits/stdc++.h>
using namespace std;
struct str{
	long long num;string s;
};
str a[200010];
long long tong[2000010];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;cin>>n;string res;
	bool f=1;
	for(int i=0;i<n;i++){
		cin>>a[i].num>>a[i].s;
		res+=a[i].s;
		tong[i]=a[i].num;
	}
	long long cnt=0;
	for(int i=0,j=res.size()-1;i<res.size(),j>=0;i++,j--){
		if(res[i]!=res[j]){
			if(tong[i]>tong[j]){
				int c=tong[i]-tong[j];
				for(int k=i;k<n;k++){
					tong[k+1]=tong[k];
				}
				tong[i]=c;
				string ls1=res.substr(0,i),ls2=res.substr(i,n);
				res=ls1+res[i]+ls2;
				res[i]=res[j];
				cnt+=tong[j];
			}else if(tong[j]>tong[i]){
				int c=tong[j]-tong[i];
				for(int k=j;k<n;k++){
					tong[k+1]=tong[k];
				}
				tong[j]=c;
				string ls1=res.substr(0,j),ls2=res.substr(j,n);
				res=ls1+res[j]+ls2;
				res[j]=res[i];
				cnt+=tong[i];
			}else{
				res[i]=res[j];
				cnt+=tong[i];
			}
			//cout<<res<<endl;
		}
	}
	cout<<cnt;
	return 0;
}
