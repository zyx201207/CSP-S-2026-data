#include<bits/stdc++.h>

using namespace std;

int n,m;
struct node{
    int d;
	int e;
};
node b[5*100000+10];
int a[5*100000+10];
int c[5*100000+10];
int f[5*100000+10];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        f[i]=0;
        b[i].d=0;
        b[i].e=0;
    }
    for(int i=1;i<=n;i++){
    	int h=1;
	    for(int j=i;j<=n;j++){
	    	if(b[a[j]].d==0){
	    		b[a[j]].d=1;
	    		c[h]=a[j];
	    		b[a[j]].e=h;
	    		h++;
			}
			else{
				h=b[a[j]].e;
				for(int k=b[a[j]].e;c[k]!=0;j++){
					b[k].d=0;
					b[k].e=0;
					c[k]=0;
				}
				b[a[j]].d=1;
	    		c[h]=a[j];
	    		b[a[j]].e=h;
	    		h++;
			}
		}
		for(int q=1;q<=n;q++){
			if(c[q]==i){
				f[i]+=1;
			}
			c[q]=0;
			b[q].d=0;
			b[q].e=0;
		}
    }
	for(int i=1;i<=m;i++){
        cout << f[i] << " ";
    }
    return 0;
}
