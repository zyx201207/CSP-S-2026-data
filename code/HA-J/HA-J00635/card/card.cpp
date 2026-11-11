#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d %d\n",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d ",&a[i]);
	for(int i=0;i<n;i++){
		vector<int> v;
		for(int j=i;j<n;j++){
			int w=1e9;
			for(int k=0;k<v.size();k++){
				if(v[k]==a[j]){
					w=k;
					break;
				}
			}
			if(w==1e9){
				v.push_back(a[j]);
			}
			else{
				v.erase(v.begin()+w,v.end());
				v.push_back(a[j]);
			}
		}
		for(int j:v)b[j]++;
	}
	for(int i=1;i<=m;i++)printf("%d ",b[i]);
	printf("\n");
	fclose(stdin),fclose(stdout);
	return 0;
}
