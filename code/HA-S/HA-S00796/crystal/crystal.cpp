#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,jishu=1;
long long a[500005],b[1000005],cf[1000005],chu;
int aa[500005],dd=2000001;
void d(int y){
	if(sum>m)return;
	if(y==chu)cf[a[y]]--;
	if(b[a[y]]!=0){
		if(cf[a[y]]>0){
		while(cf[a[y]]>0){
			jishu++;
			cf[a[y]]--;
		}
		}
	}
	sum+=jishu;
	d(y+1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>aa[i];
		a[i]=aa[i];
		int ddd=dd;
		dd=min(dd,aa[i]);
		if(ddd!=dd)chu=i;
		if(b[a[i]]==0){
		b[a[i]]=i;	
		cf[a[i]]++;
		}else {
			cf[a[i]]++;
		}
	}
	d(chu);	
	cout<<jishu;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

