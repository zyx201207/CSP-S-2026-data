#include <bits/stdc++.h>
using namespace std;
long long n,m;
int ans=0;
long long a[5000005],cnt[5000005],sum[5000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n<=5000&&m<=1000000)
    {
		int maxn=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			memset(cnt,0,sizeof(cnt));
			memset(sum,0,sizeof(sum));
			int ans=0,cc=1;
			for(int j=i;j<=n;j++)
			{
				cnt[cc]=a[j]*cc,sum[cc]=sum[cc-1]+a[j];
				cc++;
			}
			for(int j=1;j<cc;j++) 
			{
				if(sum[j]+m>=cnt[j]) ans=j;
				else break;
			}
			maxn=max(maxn,ans);
		}
		cout<<maxn;
		return 0;
	}//25
    for(int i=1;i<=n;i++) cnt[i]=a[i]*i,sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++) 
    {
		if(sum[i]+m>=cnt[i]) ans=i;
		else break;
	}//30
	cout<<ans;
	return 0;
}//30+25=55
/*
                 ????????????			    ????????????		  	  ????????????	
                ???????????????			   ???????????????		  	 ???????????????	
              ?????        ?????		 ?????        ?????		 	?????       ?????	
             ?????        ?????			?????        ?????		   ?????       ?????	
                        ?????			           ?????		      	      ?????	
                       ?????			          ?????			          	 ?????		
                      ?????				         ?????			  	        ?????		
                     ?????				        ?????			  	       ?????	
                     ?????		       			?????				       ?????		
                     ?????				        ?????			           ?????		
                     ?????				        ?????			           ?????		
																
                     ?????				        ?????			           ?????		
                     ?????				        ?????			           ?????		
                     ?????                      ?????                      ?????
.......
T1 10min jiu zuo wan le
T2 yi jiu shi yi dian si lu mei you(bi T2 jian dan de T3 bu duo le,sui ran wo T3 ye bu hui)
wei sha bu xie bao li?
da:bu hui.
ke nei zuo ye yi bi mei dong,ming tian fan xiao hai dei zhao lao shi bo yi(na zhe j zu2= qu bo yi ma?)
shang wu j zu T2 wang xie you hua tong shi 30 jin nian ye shi yu 1= wu yuan le(chinese can fly neng bu neng ba xian jiang di dian,200jiu ke yi)
希望下次s1=xian di dian,100 dui yu HB hao xiang ye bu suan tai di ba
xian zai是17:10 T2hai shi yi dian si lu mei you,xia hui bu bao s le,chun fei shi jian gao yi zai bao(ju shuo zhong kao bu kan s zu,ye bu zhi dao zdjd)
zhe hui kan neng bu neng mo ge 2=,di yi ci shuang er hao xiang ye hai ke yi(bie gao su wo xie sha 2= xian 110 zhi lei de)
hua shuo wo wei sha yao xie zhe ge ne
T1 ti jie:
lan de xie(wo ye bu yi ding neng guo)
T2 ti jie:
bu hui.
T3 ti jie:
bu hui.
T4 ti jie:
zhe ge zhe me jian dan nan dao hai you ren bu hui(wo bu shi ren,wo shi cao lv chong)
zto s1= orz zto s1= orz zto s1= orz zto s1= orz
Chinese Can Fly pls give me 1=1=1=1=1=1=1=1=1=1=1=1=(gei bu liao le...)
17:30
fa xian T1 si lu you wen ti wo hai you jiu ma?
17:40
mei jiu le
17:50
mei jiu le zhi neng xie ge 30de le...
18:10
bu chu yi wai de hua 55 2= ke neng hai shi you xi
*/
