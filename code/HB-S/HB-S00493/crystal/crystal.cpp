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
#define file "crystal"
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
	int n,m,ans=-1;sc(n,m);
	std::vector<int>a(n);
	std::vector<int>sub(n);
	for(int&i:a)sc(i);
	std::sort(a.begin(),a.end());
	sub[0]=0;
	for(int i=1;i<n;i++)
		sub[i]=sub[i-1]+(i-1)*(a[i]-a[i-1]);
	auto calc=[&sub,&a](int i,int j){
		if(i==0)return sub[j];
		return sub[j]-sub[i-1]-(i-1)*(a[j]-a[i-1]);
	};
	for(int i=0;i<n;i++){
		int l=0,r=i;
		while(l<r){
			int mid=l+r>>1;
			if(calc(mid,i)>m)l=mid+1;
			else r=mid;
		}
		ans=std::max(ans,i-l+1);
	}
	pr(ans,'\n');
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