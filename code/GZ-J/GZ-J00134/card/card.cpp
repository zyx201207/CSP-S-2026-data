//GZ-J00134 南白初级中学 唐清倾 
#include <bits/stdc++.h>
using namespace std;
int n,m;//5*10^5   3*10^5
int a[500001]={},b[300001]={},c[300001]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){//5*10^5
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){//5*10^5
		for(int j=b[a[i]];j<=n;j++){//最后一次出现a[i]的位置，就从这个位置开始看 
			if(b[a[j]]>j) j=b[a[j]]-1;//5*10^5
			else{
				c[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){//3*10^5
		cout<<c[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
}

