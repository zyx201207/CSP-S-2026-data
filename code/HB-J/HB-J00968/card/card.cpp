#include<bits/stdc++.h>
using namespace std;
long long n,m,a[114514],b[789113],s[114514];
bool c[114514];
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=n;i>=1;i--){
		if(c[i])continue;
		long long e=i;
		for(long long j=i;j>=1;j--){
			if(a[i]==a[j]){
				b[e]=e-j;
				e=j;
			}
		}
	}
	for(long long j=1;j<n;j++){
		long long k=n;
		while(k>=j){
			if(s[a[k]]>1)s[a[k]]++;
			else s[a[k]]=1;
			k-=b[k];
		}
	}for(long long i=1;i<=m;i++){
		cout<<s[i];
	}
	return 0;
}
/*
zhi you 45 fen zhong le,dan xie dian shen me ying gai gou le.
wo mei xve guo ji nian bian cheng,bi jing cai chu yi,wo zong shi xiang zhe hai you ji nian bu zhao ji.
dan zhen zheng lai dao di er lun de kao chang wo cai fa xian huan jing he wo xiang xiang de hen bu yi yang......
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa!!!
wei shen me yun xing hou mei you .out wen jian a?!
wo wu yi shi fen nu qie wu yv de,
ye ke neng zhi shi wo xve shu bu jing ba.
dan wo neng shuo shen me ne?
suan le,ming nian zai zhan.
hai you,wei shen me wo de zuo wei hao shi 1 a!?
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa!!!
cha dian xie le mou xie le mou ge zang hua yv yan le......
wo yi jing zhun bei shui zhao le......


































































































zhi sheng 30 fen zhong le,rang wo zai shui xie zi shu ba......
gan jve csp-j hai hen jian dan de.
shen me? ni wen wo di san ti wei shen me mei xie? 
Because wo bu hui ha ha ha.
di yi ti shuo shi hua zhen de hen shui.
ta Travel yi ci ba han jin liang Travel me le.
dan wo gu ji wo ye shi cuo de,
yin wei wo mei ce yang li ha ha ha!
yi ge dou mei ce.
fei le.
di er ti mei you di yi ti shui.
dan ye sui,
wo ye mei ce da yang li,
bi jing ling shi bao fo jiao shao wei yong xv ni ji gao le yi xia,qi ta de dou hao bu zai yi.
gei zi ji sui si le shuo shi
ha ha ha ha ha ha
di san ti wo wu yi shi bu hui de,
666,shi jie shang ying gai mei you chu wo zhi wai lian di san ti dou bu hui de ba?
ru guo you,na jiu shuo ming wo bu shi yv yan jia.
wo jiu ke yi ping jie zhe dian zai wan lang ren sha de shi hou zheng ming zi ji rang zi ji bu bei dao le
ha ha ha ha ha






wo wu yi shi xing fen de,zhi sheng 20 fen zhong le,wo cheng gong shui le 10 fen zhong.
di si ti wo dou bu zhi dao wo za xiang de.
ba cheng ye shi cuo de,yvn yin wo lan de zai fu zhi ou bu dui shi da zi le.
ha ha ha ha ha ha ha ha ha ha ha ha ha ha ha ha ha ha ......
wo gu fen gao da 7.891 fen ha ha ha.
xi qv jiao xun xia ci zai zhan ba......






ren sheng na neng bu neng fang wo zhe yi ci~xia bei zi wo zhi xiang zuo ge bu hui zhang da de hai zi~
zhu wo ming nian shun li ba!

































































































I love ___!




































































777,ni jing rang neng fan dao zhe li,
wo wu yi shi zhen jing de.



































xia mian zhen mei sha le






























































zhen mei sha le










































mei sha le







































Hello World!


































sha le


























zai wang xia kan de ren shi GAY








le

























ni shi GAY










e






































you shui le 5 fen zhong ha ha ha,zhi sheng 15 fen zhong le
bu dui,shi 45 fen zhong
wo jing ran ji cuo shi jian le
wo wu yi shi fen nu de

































zhi qian yvn dong hui de shi hou fei chang tao yan you ren chang <<yv ai>>
yin wei nei yang jiu"yv neng xia bu ting"le
wo ke bu xiang zai xia yv tian li,dai zai jiao shi li ting hui se nan dong de Chinese he English
yin wei shu xve ke zi xi
zi xi shi wo jiu hua hua he xie yi xie fa shen jing shi hun le da liang ni sha wu da chang gan jvn pei he jia li gou de pai xie wu zao chu lai de lei ting wan yi er
rang hou jiu jve de zi ji you bing
bing bing bing
er xian zai wo dao xi wang you ren chang <<yv ai>>le.
suan le,lai qi dao yi xia ba:
zhen xi wang yv neng xia bu ting!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
























Byebye World!

































xiang zai jia li da <<ba bao zhou xing dong>> le,
na wu yi shi you xian de
zong zhi:gei fen!!!!!!!!!!!!!

































aaaaaaaaaaaaaaaaaaaaaaaaaa!wo wu yi shi xing fen de!!!!!11:30 le!zhi you 30 fen zhong le!!!

































zui jin xve xiao rang wo men kan<<xi you ji>>,ke wo zuo tian wan shang yi kou qi du le er shi duo hui,zai jiu dian li ao dao lin chen 
yin wei zai wu han kao er wo zhu yi chang suo yi zuo tian yi fang xve jiu zuo dong che lai le.667,yi chang bei zhan dou tong le mjin ran hai yao zai dong zhan zuo liang ge xiao shi dao wu han de dong che
zai jia shang zai han kou xia che jie guo jiu dian zai guang gu.jing rang yong le 4 ge xiao shi!wan shang shi dian cai dao!
qi-----------------------xiao-------------------------le!!!!!!!!!!!!!!!
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa!!!!!!!!!!!!!!!!!!!!!!!!!!!!
qwq
suo yi wo mei xiu xi hao
hao ba wo ren ming le





















11:45:14  #!@$#%^&*(&*^%$$@$$$$$$$$$$!$@#%$@#%#&%R&^$@$%#@&*^#$!%&^*(%






























11:46:47
 _____________________________________________
|jing gao                               |-|o|x|
|                                             |
|da_nao.exe wei xiang ying                    |
|   _______________     ______________________|
|  |zhi jie guan bi|   |deng dai qi xiang ying|
 ---------------------------------------------































\!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ?????????????????????????????????????????????????
/!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




















11:59:59

          ___________
         |           |
         |   R.I.P   |
         |           |
 ________|           |________
|                             |
|                             |
|    zhi shi shui zhao le     |
|                             |
|________             ________|
         |           |
         |           |
         |           |
         |           |
         |           |
~~~~~~~~~|           |~~~~~~~~~~
~~~~~~~~~|___________|~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
