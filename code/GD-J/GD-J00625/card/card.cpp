#include<bits/stdc++.h>
#define N 500007
#define V 300007
#define ll long long
#define hhy11_yaoAKJzu OK wo ye shi zhi jie zai 10:05 ak le ran hou ye dui pai wan le (zai 10:53)
#define hhy11_666 dui de yin wei zhu yi shi xiang li mian bu rang wo zai zhu shi li mian xie he kao shi wu guan de dong xi
#define hhy11_sto_craftmine_f suo yi wo zhi neng zai zhe ge define li mian xie le
#define craftmine_f_akioi bu zhi dao hui bu hui bei fa xian ne
#define luoguzhanghao hhy11_
#define AK_de_shi_jian 10:05
#define youji1 wo zui hou yi ti yi kai shi du cuo ti le suo yi wo AK de bi jiao wan
#define youji2 wo ye bu zhi dao zhe ci neng bu neng AK yin wei wo pa hui chu wen ti
#define youji3 dan shi wo hou mian san ti dou dui pai le suo yi wo ye mei you na me pa
#define youji4 wo men xu yao zhu yi dao di yi ti de D he F shi xiang lin de,zhong jian mei you E
#define youji5 suo yi wo jue de you yi bu fen ren hui zai zhe li gua fen,qi shi ye jiu 15 fen,dui yu bu AK de ren ye bu shi hen zhong yao
#define youji6 dan shi zai te shu xing zhi li mian ye shi you ti xing,sui ran mei you shen me ren hui kan Jt1 de te shu xing zhi
#define youji7 wo bi jiao dan xin xia wu de S zu yin wei wo jin tian yi zhi zai liu bi ti,xi wang bu yao ying xiang wo de zhuang tai
#define youji8 2026CSP-J/S rp++!!!
#define youji9 hhy11_ sto craftmine_f orz hhy11_
#define finish_travel_time_xxx 8:44
#define finish_string_time_xxx 8:57
#define finish_and_time_xxx 9:05
#define finish_card_time_xxx 10:05
#define jieyamima Trick||Treat!
#define aaaaaaaabbb zui hou yi ci J zu le,bie ren dou shi chu er jiu AK le,jiu wo chu san cai neng ak,gei cicief song qian le
#define my_left wo zuo bian na ge ren ye shi shen le,zhi jie kao shi de shi hou yao chu qu chi dong xi
#define Jzudedaima J zu de dai ma dou hao duan a,you dian bu shi ying
#define difficulties_1234 hong cheng cheng huang
#define dsfadfdsfdf zhe ge checker ju ran xian shi bu chu wo de ming zi wo zhen de nu le

using namespace std;

int n, m;
int a[N], cnt[V], f[N], lst[V], mr[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		lst[a[i]] = i;
		cnt[a[i]]++;
	}
	for(int i = 1;i <= m;i++){
		f[i] = cnt[i];
	}
	for(int i = 1;i <= n;i++){
		if(i > 1 && i - 1 == lst[a[i - 1]]){
			f[a[i]] += f[a[i - 1]];
		}
	}
	for(int i = 1;i <= m;i++){
		cout << f[i] << ' ';
	}
	
	return 0;
}
