#include<type_traits>
#include<cstdint>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<unistd.h>
#include<fcntl.h>
namespace IO{
	struct Scanner{
		static constexpr int buf=1<<20;
		char in[buf],*p1,*p2;
		int fd;bool eof;
		#define gc()(eof?4:(p1==p2&&(p2=(p1=in)+read(fd,in,buf)),p1==p2?(eof=1,4):*p1++))
		Scanner(int fd=0):fd(fd){p1=p2=in;eof=0;}
		char peek(){return*p1;}
		void operator()(char&val){if(!eof)val=gc();}
		void operator()(char*val){
			if(eof)return;
			char ch;
			while(isspace(ch=gc()));
			if(eof)return;
			*val=ch;
			while(isgraph(*++val=gc()));
			*++val=0;
		}
		void operator()(std::string&val){
			if(eof)return;
			char ch;
			while(isspace(ch=gc()));
			if(eof)return;
			val=ch;
			while(isgraph(ch=gc()))val+=ch;
		}
		template<typename T>
		typename std::enable_if<std::is_integral<T>::value,void>::type
		operator()(T&val){
			if(eof)return;
			char ch;
			while(isspace(ch=gc()));
			if(eof)return;
			bool flag=ch==45;
			flag&&(ch=gc()),val=ch^48;
			while(isdigit(ch=gc()))val=val*10+(ch^48);
			flag&&(val=-val);
		}
		template<typename T,typename...R>
		__attribute__((always_inline))
		void operator()(T&val,R&...rest){
			operator()(val),operator()(rest...);
		}
	};
	struct Printer{
		static constexpr int buf=1<<20;
		char out[buf],*p3;
		int fd;
		#define pc(ch)(p3==(out+buf)&&(write(fd,p3=out,buf)),*p3++=ch)
		Printer(int fd=1):fd(fd){p3=out;}
		~Printer(){write(fd,out,p3-out);}
		void operator()(char val){pc(val);}
		void operator()(char*val){
			while(*val)pc(*val++);
		}
		void operator()(const char*val){
			while(*val)pc(*val++);
		}
		void operator()(const std::string&val){
			operator()(val.data());
		}
		template<typename T>
		typename std::enable_if<std::is_integral<T>::value,void>::type
		operator()(T val){
			if(!val){pc(48);return;}
			bool flag=0;
			if(std::is_signed<T>::value&&!T(val<<1))flag=1,val/=10;
			if(val<0)pc(45),val=-val;
			static char tmp[64],cnt;cnt=63;
			tmp[--cnt]=0;
			while(val)tmp[--cnt]=48^(val%10),val/=10;
			operator()(tmp+cnt);
			if(flag)pc(56);
		}
		template<typename T,typename...R>
		__attribute__((always_inline))
		void operator()(T val,R...rest){
			operator()(val),operator()(rest...);
		}
	};
}
#define file "subway"
#define atashi return
#define wa
#define hito 0
#define janai
#define int int64_t
signed main(){
	int infd=0,outfd=1;
	if(!access(file".in",R_OK))
		access(file".out",F_OK)||remove(file".out"),
		infd=open(file".in",O_RDONLY),
		outfd=open(file".out",O_WRONLY|O_CREAT,0644);
	IO::Scanner sc(infd);
	IO::Printer pr(outfd);
	int c,n,m,d,q;
	sc(c,n,m,d,q);
	std::vector<std::vector<int>>station(m+1),walk(m+1),
		mp(n+1,std::vector<int>(n+1,(int)1e14));
	for(int i=1;i<=n;i++)
		mp[i][i]=0;
	std::vector<int>w(m+1);
	for(int i=1;i<=m;i++)sc(w[i]);
	for(int i=1,k;i<=n;i++){
		sc(k);
		for(int j=0,a,t;j<k;j++)
			sc(a,t),station[a].push_back(i),walk[a].push_back(t);
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<station[i].size()-1;j++)
			for(int k=j+1;k<station[i].size();k++){
				int J=station[i][j],K=station[i][k];
				int time=walk[i][j]+walk[i][k];
				mp[J][K]=std::min(mp[J][K],time);
				mp[K][J]=std::min(mp[K][J],time);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(j==i||j==k)continue;
				mp[i][j]=std::min(mp[i][k]+mp[k][j],mp[i][j]);
			}
		}
	while(q--){
		int x,y,ans=INT64_MAX;
		sc(x,y);
		for(int i=0;i<station[x].size();i++)
			for(int j=0;j<station[y].size();j++)
				ans=std::min(ans,walk[x][i]+walk[y][j]+
					mp[station[x][i]][station[y][j]]);
		pr(ans+w[x]+w[y],'\n');
	}
	atashi wa hito janai;
}
//dakedo daijoubunantekoiwadokonimonaino
//dakara mousoukanshoudaishourenmei
//aioidaiterisouosakenda
//ikibanonaigushanomorodii
//saijousentenseiterepouteishon
//nankaidattekasaneteikunda
//owarinakiainomanimani saa

//dakedo daijoubunantekoioshinjiteshimauyo
//dakara tsuushouaijoutaishounenrei
//aionikundemamottaisouga
//tadashikuyugamihajimaruno
//saiteijandousetaijinroushon
//nankaidattekizutsukeaunda
//mazariauainofirosofii saa

//daketo daijoubunanteusoooboedeshimauyo
//dakara mousoukanshoudaishourenmei
//aioidaiterisouosakenda
//ikibanonaigushanomorodii
//saijousentenseiterepouteishon
//nankaidattekasaneteikunda
//owarinakiainomanimani saa
//tsuushouaijoutaishounenrei
//aionikundemamottaisouga
//tadashikuyugamihajimaruno
//saiteijandousetaijinroushon
//nankaidattekizutsukeaunda
//mazariauainofirosofii saa

//senbonzakurayorunimagire
//kiminokoemotodokanaiyo
//kokowautagehaganenoori
//sonodantoudaidemioroshite
//sanzensekaitokoyonoyami
//nagekuutamokikoenaiyo
//seirannosoraharukakanata
//sonokousenjuudeuchinuite

//senbonzakurayorunimagire
//kiminokoemotodokanaiyo
//kokowautagehaganenoori
//sonodantoudaidemioroshite
//sanzensekaitokoyonoyami
//nagekuutamokikoenaiyo
//kibounookaharukakanata
//sonosenkoudanouchiagero

//senbonzakurayorunimagire
//kiminokoemotodokanaiyo
//kokowautagehaganenoori
//sonodantoudaiotobiorite
//senbonzakurayorunimagire
//kimigautaibokuwaodoru
//kokowautagehaganenoori
//saakousenjuudeuchimakure