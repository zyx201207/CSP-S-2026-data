#include<bits/stdc++.h>
using namespace std;
long long a[200050];
char c[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a1=0,a2=0,ans=0;
	char c1='\0',c2='\0';
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld %c",&a[i],&c[i]);
	int l=0,r=n+1;
	while(l<r){
		if(a1==0){
			l++;
			a1=a[l];
			c1=c[l];
		}
		if(a2==0){
			r--;
			a2=a[r];
			c2=c[r];
		}
		int temp=min(a1,a2);
		if(c1!=c2)ans+=temp;
		a1-=temp;
		a2-=temp;
	}
	cout<<ans;
	return 0;
}
/*zhe ge ren xian de mei shi gan zai di er ti zhe li da le yi chang chuan pin yin
  wo liu le yi ge shen mi cai dan(cun yi
  ran hou jiu shi jin tian shi wo sheng ri ya,kao wan shi hui jia jiu neng guo sheng ri le ya
  wo zhe me zuo zhen de neng shang mi huo xing wei da shang ma
  fan yi guan xin ku le,he deng yi li neng jian chi kan wan
  gun mu
  -|==========> zhe shi yi ba jian
  I'm nooooooooooooooooooooooooooooooob
  luogu@Lung_fog
*/
