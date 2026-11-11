#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n];
    for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int cut=a[0] and a[1];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)continue;
			if(a[i] and a[j] > cut)cut=a[i] and a[j];
		}
	}
	printf("%d",cut);
}
