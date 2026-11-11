#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long n,m,a[10005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long shu;
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			shu=shu+2;
			break;
		}
		else if(a[i]<a[i+1]||a[i]+1<a[i+1]){
			if(a[i]+1){
				m=m-1;
			}
			shu=shu+2;
			break;
		}
		else{
			if(a[i]+1){
				m=m-1;
			}
			shu=shu+2;
			break;
		}
	}
	cout <<shu;
	fclose(stdin);
	fclose(stdin);
	return 0;
}
