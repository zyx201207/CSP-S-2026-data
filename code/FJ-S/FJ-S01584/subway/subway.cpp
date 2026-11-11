#include<bits/stdc++.h>
using namespace std;
const int Mn=4e5+5,L=1e8;
int A[L],sum,cons,c,n,m,d,q,w[Mn],k[Mn],a[Mn][Mn],t[Mn][Mn],x[Mn],y[Mn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	/*依旧是一场发懵的复赛，第一题30min才A，直接吓哭了<^_^> 
		让我们来尝试复习岳阳楼记
		                《岳阳楼记》
									范仲淹
			庆历四年春，滕子京谪守巴陵郡。越明年，政通人和，百废俱兴。乃重修岳阳楼，
		增其旧制，刻唐贤今人诗赋于其上，属于作文以记之。
			与观乎巴陵胜状,在洞庭一湖，衔远山，吞长江，浩浩汤汤，横无际涯，朝晖夕阴
		气象万千。..........."先天下之忧而忧，后天下之乐而乐".........微斯人，吾谁与归？
		100+100+80+60=340
		30+0+0+0=30
		
		
	*/ 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			A[a[i][j]]++;
		}
	}
	for(int i=1;i<=L;i++){
		if(A[i]==2){
			cons=i;
			break;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		bool o=false,p=false,oo=false,pp=false;
	int ans1=0,ans2=0,ans11=0,ans22=0;
	for(int i=1;i<=k[1];i++){
		if(x[i]==a[1][i]){
			o=true;
			ans1=i;
		}
		if(y[i]==a[1][i]){
			p=true;
			ans2=i;
		}
	} 
	for(int i=1;i<=k[1];i++){
		if(x[i]==a[2][i]){
			oo=true;
			ans11=i;
		}
		if(y[i]==a[2][i]){
			pp=true;
			ans22=i;
		}
	}
	int z=0;
	sum+=w[x[i]]+w[y[i]]; 
	if(o&&p){
		int z=0;
		for(int i=ans1;i<=ans2;i++){
			z+=t[1][i];
		}
		sum+=z;
	}else if(oo&&pp){
		int z=0;
		for(int i=ans11;i<=ans22;i++){
			z+=t[2][i];
		}
		sum+=z;
	}else{
		if(o&pp){
			for(int i=ans1;i<=cons;i++){
			z+=t[1][i];
			}
			for(int i=cons;i<=ans22;i++){
			z+=t[2][i];
			}
			sum+=z;
		}else if(oo&p){
			for(int i=ans11;i<=cons;i++){
			z+=t[1][i];
			}
			for(int i=cons;i<=ans2;i++){
			z+=t[2][i];
			}
			sum+=z;
		}
	}
	cout<<sum<<endl;
	}
	
	return 0;
}

