#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n,m,a[500009],b[500009],c,d[300009];
int main(int argc, char** argv) {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		c=i;
	    for(int j=i;j<=n;j++){
			b[c]=a[j];
			for(int z=i;z<j;z++){
				if(b[z]==a[j]){
					c=z;
					b[z]==a[j];
				}
			}
			c++;
		}
		for(int j=i;j<c;j++){
			cout << b[j] << ' ';
		}
		cout << endl;
	    for(int y=1;y<=m;y++){
		    for(int x=i;x<c;x++){
		    	if(b[x]==y){
		    		d[y]++;
		    		x+=c;
				}
			}
	    }
	}
	for(int i=1;i<=m;i++) cout << d[i] << ' ';
	return 0;
}
