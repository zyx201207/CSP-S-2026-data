#include <iostream>
using namespace std;
bool used[3963167],fl;
int a[555555],m,n,res[3963167];
int card[323532];
int in,tail,h;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	while(h<n){
		for(int i=h;i<n;i++){
			for(int j=0;j<tail;j++)
				if(a[i]==card[j])
					fl=true,in=j;
			if(!fl) card[tail++]=a[i],used[a[i]-1]=true;
			else{
				for(int j=in+1;j<tail;j++)
					used[a[j]-1]=false,card[j]=0;
				tail=in+1;
			}
			fl=false,in=0;
		}
		for(int i=0;i<m;i++)
			res[i]+=used[i],used[i]=false;
		for(int i=0;i<tail;i++)
			card[i]=0;
		h++,tail=0;
	}
	for(int i=0;i<m;i++)
		cout << res[i] << " ";
	return 0;
}
