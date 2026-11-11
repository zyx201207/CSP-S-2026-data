//  GZ-J00064  兰椿楸  毕节七星关东辰实验学校
#include<iostream>
#include<cmath>
using namespace std;
struct m{
	long long a;
	char b;
}m[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long difz=0;
	long long dif[200005];
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i].a>>m[i].b;
    }
	for(int i=1;i<=n/2;i++){
		long long j=n+1-i;
		if(m[i].b==m[j].b){
		    dif[i]=m[i].a -m[j].a;
		    m[i].a-=dif[i];
		}
		if(m[i].b!=m[j].b&&m[i+1].b!=m[j-1].a){
			dif[i]=min(m[i].a,m[j].a)+abs(m[i].a -m[j].a);
		}
		if(m[i].b!=m[j].b&&m[i+1].b==m[j-1].a){
			dif[i]=min(m[i].a,m[j].a);			
		}
		difz+=dif[i];
		if(difz<0)difz=0;
	}
	cout<<difz;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

