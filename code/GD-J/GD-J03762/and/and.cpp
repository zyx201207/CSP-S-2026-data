#include<iostream>
#include<cstdio>
using namespace std;
int a[(int)2e5];
void swap(int &x,int &y){
	x^=y;
	y^=x;
	x^=y;
}int ands(int x){
	int sum=0;
	while(x){
		sum+=x&1;
		x>>=1;
	}return sum;
}void sort(int *begin,int size){
	if(size==1)
		return;
	sort(begin,size>>1);
	sort(begin+(size>>1),(size>>1)+(size&1));
	for(int i=(size>>1)-1,len=0;i>=0;i--){
		for(int j=i+1;j+len<=i+1+(size>>1)+(size&1);j++){
			int ans[2]={ands(*(begin+j-1)),ands(*(begin+j))};
			if(ans[0]<ans[1]||ans[0]==ans[1]&&*(begin+j-1)<*(begin+j))
				swap(*(begin+j-1),*(begin+j));
			else{
				len=i+1+(size>>1)+(size&1)-j-len;
				break;
			}
		}
	}
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=-1;
	cin>>n>>m;
	for(int i=0;i<n;cin>>a[i++]);
	sort(a,n);
	for(int i=0;i<m;ans&=a[i++]);
	cout<<ans;
	return 0;
}
