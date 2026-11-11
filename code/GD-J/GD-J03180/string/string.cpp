#include <bits/stdc++.h> 
using namespace std;
const int N=2e5+1;
struct point{
	int sum;
	char k;
};
point a[N];
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,cnt=0;
	cin >>n;
	bool p=0,p2=0;
	for(int i=1;i<=n;i++){
		cin >>a[i].sum>>a[i].k;
		cnt=(cnt+a[i].sum)/2;
		if(a[i].k!=a[1].k)p=1;
	}if(!p){
		cout <<"0";
	}else{
		if(cnt)p2=1;
		int i=1,j=n;
		long long ans=0;
		int t=n;
		while(t && i<j){
			if(t==1 && p2)break;
			if(a[i].sum==a[j].sum){
				if(a[i].k!=a[j].k)ans=ans+a[j].sum;
				t-=2;
				i++,j--;
			}else if(a[i].sum>a[j].sum){
				a[i].sum-=a[j].sum;
				t--;
				if(a[i].k!=a[j].k)ans=ans+a[j--].sum;
			}else{
				a[j].sum-=a[i].sum;
				t--;
				if(a[i].k!=a[j].k)ans=ans+a[i++].sum;
			}
		}
		cout <<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
