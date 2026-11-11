#include<iostream> 
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int a[500005];
int l[500005],r[500005];
int t[500005];
int bis[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		memset(bis,0,sizeof(bis));
		r[0]=a[i];
		l[a[i]]=0;
		l[500000]=a[i];
		r[a[i]]=500000;
		bis[a[i]]=i;
		for(int j=i+1;j<=n;j++){
			if(bis[a[j]!=0]){
				l[a[j]]=a[l[bis[a[j]]]];
				r[l[a[bis[a[j]]]]]=a[j];
			}else{
				l[a[j]]=l[500000];
				r[l[500000]]=a[j];
			}
			bis[a[j]]=j;
			r[a[j]]=500000;
			l[500000]=a[j];
		}
		int idx=0;
		while(r[idx]!=500000){
			t[r[idx]]++;
			idx=r[idx];
		}
		cout<<1;
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	fclose(stdin);
    fclose(stdout);
    return 0;
}
 
