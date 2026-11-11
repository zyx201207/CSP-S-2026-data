#include<iostream>
using namespace std;
const int MAXN=5e5+5;
int n,m;
int a[MAXN],last[300005];
int f[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		last[a[i]]=i;
		f[i]=1;
	}
	for (int i=1;i<=n;i++){
		if (last[a[i]]==i) f[i+1]+=f[i];
		else f[last[a[i]]]+=f[i];
	}
	for (int i=1;i<=m;i++) cout<<f[last[i]]<<" ";
	return 0;
}
// rp++;
/*
26-10-31 9:37
qie wan suo you ti le
zen me gan jue shi jian guo de zhe me man?
25 nian J na le 1= de wo zai xiang
wo xian zai wei shen me hui zuo zai zhe li?
......
26-10-31 9:48
shui gei wo jiao guo lai fa zuo lai le?
26-10-31 10:00

tai wu liao le , mo ge wen yan wen ba.

   24 ke : zhou ji feng qi wan na jian

zhou ji shen xiu ba chi, xing mao yi li.
zhao guan kui jing, wei qi qi wen yue:
"wu shu yu xu gong mei?"
xu gong,qi guo mei li zhe ye.
qi qi yue:"jun mei shen, xu gong he neng ji jun ye?"
ji bu zi xin,wen qi qie yue:
"wu shu yu xu gong mei?"
qie yue:"xu gong he neng ji jun ye?"
dan ri,ke cong wai lai,yu zuo tan,wen:
"wu yu xu gong shu mei?"
ke yue:"xu gong bu ru jun mei ye."
ming ri xu gong lai,shu shi zhi, zi yi wei bu ru.
kui jing er zi shi,you fu ru yuan shen.
mu qin er si zhi ,yue:
"wu qi zhi mei wo zhe ,si wo ye.
qie zhi mei wo zhe , wei wo ye.
ke zhi mei wo zhe , yu you qiu yu wo ye."

yu shi ru chao jian wei wang yue:
"chen cheng zhi bu ru xu gong mei.
chen zhi qi si chen,chen zhi qie wei chen,chen zhi ke yu you qiu yu chen.
jin qi di fang qian li ,bai er shi cheng.
gong fu zuo you mo bu si wang.
chao ting zhi chen mo bu wei wang.
si jin zhi nei bo bu you qiu yu wang.
you ci guan zhi,wang zhi bu shen yi."

wang yue:"shan." nai xia ling:
"qun chen li min neng mian ci gua ren zhi zuo zhe, shou shang shang.
shang shu jian gua ren zhe, shou zhong shang.
neng bang yi yu shi chao, wen gua ren zhi er zhe, shou xia shang."
ling chu xia , qun chen jin jian, men ting ruo shi.
shu yue zhi hou , shi shi er jian jin.
qi nian hou, sui yu yan,wu yan ke jin.
yan, zhao , han, wei wen zhi,jie chao yu qi.
ci suo wei zhan sheng yu chao ting. 

luo gu shang you mei you nong mi zhi xing wei da shang de.
bang mang pi gai yi xia bei.

26-10-31 11:51
zhong yu yao jie shu le ma...
*/
