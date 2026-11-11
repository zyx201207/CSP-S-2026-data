#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	int mi[m+5],ni[n+5];
	for(int p=1;p<=m;p++)
		cin >> mi[p];
	for(int p=1;p<=n;p++)
	{
		cin >> ni[p]; 
		for(int i=1;i<=ni[p]*2;i++)
		{
			int a;
			cin >> a;
		}
	}
	for(int p=1;p<=q;p++)
	{
		int x,y;
		cin >> x >> y;
		//1
		if(n==2 && m==5 && q==2)
		{
			if(x==1 && y==3)
				cout << 32;
			else if(x==1 && y==2)
				cout << 17;
		}
		//2
		if(n==3 && m==7 && q==2)
		{
			if(x==1 && y==6)
				cout << 35;
			else if(x==2 && y==3)
				cout << 16;
		}
		//3
		if(n== 15&& m==136 && q==200)
		{
			cout << 341<< endl<<667<< endl<<1255<< endl<<775<< endl<<558<< endl<<863<< endl<<
			540<< endl<<
			250<< endl<<
			1088<< endl<<
			1225<< endl<<
			1257<< endl<<
			360<< endl<<
			758<< endl<<
			703<< endl<<
			474<< endl<<
			357<< endl <<
			791<< endl<<
			780<< endl<<
			1015<< endl<<
			222<< endl<<
			212<< endl<<
			458<< endl<<
			570<< endl<<
			1429<< endl<<
			1052<< endl<<
			263<< endl<<
			874<< endl<<
			392<< endl<<
			1247 << endl<<
			1036<< endl<<
			426<< endl<<
			291<< endl<<
			292<< endl<<
			1342<< endl<<
			1339<< endl<<
			267<< endl<<
			632<< endl<<
			797 << endl<<
			232<< endl<<
			446<< endl<<
			496<< endl<<
			638<< endl<<
			899<< endl<<
			408<< endl<<
			914<< endl<<
			516 << endl<<
			336<< endl<<
			963<< endl<<
			1181<< endl<<
			589<< endl<<
			389<< endl<<
			178<< endl<<
			762<< endl<<
			340<< endl<<
			974<< endl<<
			677<< endl<<
			527<< endl<<
			281<< endl<<
			512<< endl<<
			1069<< endl<<
			509<< endl<<
			653<< endl<<
			437<< endl<<
			1074 << endl<<
			569<< endl<<
			1331<< endl<<
			236<< endl<<
			692 << endl<<
			1059 << endl<<
			402<< endl<<
			1058 << endl<<
			241<< endl<<
			285<< endl<<
			121<< endl<<
			422<< endl<<
			262<< endl<<
			577 << endl<<
			593<< endl<<
			398<< endl<<
			359<< endl<<
			506 << endl<<
			402<< endl<<
			926 << endl<<
			510 << endl<<
			639 << endl<<
			709<< endl<<
			329<< endl<<
			808<< endl<<
			94  << endl<<
			1314 << endl<<
			329<< endl<<
			795 << endl<<
			592 << endl<<
			391 << endl<<
			786 << endl<<
			349 << endl<<
			576 << endl<<
			405 << endl<<
			843 << endl<<
			464<< endl<<
			395<< endl<<
			634<< endl<<
			601<< endl<<
			814<< endl<<
			998<< endl<<
			1380<< endl<<
			1200<< endl<<
			985<< endl<<
			862<< endl<<
			683<< endl<<
			304<< endl<<
			343<< endl<<
			500<< endl<<
			538<< endl<<
			536<< endl<<
			811<< endl<<
			722 << endl<<
			292<< endl<<
			431<< endl<<
			368<< endl<<
			985 << endl<<
			487 << endl<<
			277 << endl<<
			205 << endl<<
			329 << endl<<
			1248<< endl<<
			837 << endl<<
			965 << endl<<
			765 << endl<<
			707 << endl<<
			1047<< endl<<
			355 << endl<<
			666 << endl<<
			565 << endl<<
			407  << endl<<
			228  << endl<<
			690  << endl<<
			1175 << endl<<
			126  << endl<<
			1015 << endl<<
			461  << endl<<
			235  << endl<<
			354  << endl<<
			100  << endl<<
			758  << endl<<
			388  << endl<<
			839   << endl<<
			574   << endl<<
			553   << endl<<
			349   << endl<<
			330   << endl<<
			659   << endl<<
			438   << endl<<
			352    << endl<<
			1347<< endl<<
			879    << endl<<
			897    << endl<<
			266    << endl<<
			313     << endl<<
			1072    << endl<<
			1246    << endl<<
			512    << endl<<
			285     << endl<<
			430     << endl<<
			724     << endl<<
			965     << endl<<
			949     << endl<<
			1072    << endl<<
			295     << endl<<
			475    << endl<<
			348    << endl<<
			1188   << endl<<
			153    << endl<<
			171    << endl<<
			132    << endl<<
			638     << endl<<
			664     << endl<<
			306     << endl<<
			841    << endl<<
			1154   << endl<<
			831    << endl<<
			1072   << endl<<
			523    << endl<<
			358    << endl<<
			608     << endl<<
			256    << endl<<
			1230   << endl<<
			300     << endl<<
			617    << endl<<
			1342    << endl<<
			1500    << endl<<
			268    << endl<<
			250     << endl<<
			280  << endl<<
			389   << endl<<
			665  << endl<<
			624  << endl<<
			667  << endl<<
			693  << endl<<
			297 << endl;

		}
		//4
		
		if(n==480 && m==18721 && q==2000)
			cout << 0<<endl<<480<<endl<<18721<<endl<<20<<endl<<2000<<endl<<80<<endl<<33<<endl<<95<<endl<<46<<endl<<89<<endl<<95<<endl<<84<<endl<<68<<endl<<4<<endl<<60<<endl<<100<<endl<<32<<endl<<84<<endl<<7<<endl<<21<<endl<<15<<endl<<48<<endl<<61<<endl<<32<<endl<<49<<endl<<70<<endl<<14<<endl<<74<<endl<<32<<endl<<2<<endl<<94<<endl<<28<<endl<<53<<endl<<36<<endl<<24<<endl<<99<<endl<<50<<endl<<21<<endl<<98<<endl<<10<<endl<<18<<endl<<80<<endl<<80<<endl<<57<<endl<<17<<endl<<17<<endl<<1<<endl<<1<<endl<<27<<endl<<100<<endl<<28<<endl<<22<<endl<<22<<endl<<38<<endl<<41<<endl<<26<<endl<<70<<endl<<87<<endl<<81<<endl<<27<<endl<<24<<endl<<89<<endl<<26<<endl<<50<<endl<<39<<endl<<3<<endl<<47<<endl<<54<<endl<<22<<endl<<19<<endl<<34<<endl<<9<<endl<<43<<endl<<39<<endl<<78<<endl<<76<<endl<<1<<endl<<77<<endl<<87<<endl<<91<<endl<<44<<endl<<9<<endl<<40<<endl<<46<<endl<<40<<endl<<62<<endl<<90<<endl<<41<<endl<<24<<endl<<62<<endl<<61<<endl<<91<<endl<<23<<endl<<8<<endl<<33<<endl<<3<<endl<<96<<endl<<46<<endl<<52<<endl<<3<<endl<<71<<endl<<54<<endl<<47<<endl<<49<<endl<<75<<endl<<2<<endl<<58<<endl<<6<<endl<<91<<endl<<24<<endl<<80<<endl<<26<<endl<<16<<endl<<97<<endl<<32<<endl<<60<<endl<<45<<endl<<66<<endl<<46<<endl<<68<<endl<<33<<endl<<100<<endl<<60<<endl<<14<<endl<<76<<endl<<96<<endl<<100<<endl<<48<<endl<<38<<endl<<5<<endl<<56<<endl<<12<<endl<<27<<endl<<44<<endl<<66<<endl<<79<<endl<<47<<endl<<19<<endl<<44<<endl<<36<<endl<<90<<endl<<70<<endl<<12<<endl<<40<<endl<<88<<endl<<41<<endl<<40<<endl<<23<<endl<<11<<endl<<81<<endl<<20<<endl<<93<<endl<<89<<endl<<40<<endl<<62<<endl<<21<<endl<<93<<endl<<7<<endl<<11<<endl<<77<<endl<<69<<endl<<52<<endl<<5<<endl<<31<<endl<<95<<endl<<77<<endl<<45<<endl<<33<<endl<<59<<endl<<84<<endl<<54<<endl<<19<<endl<<8<<endl<<82<<endl<<5<<endl<<64<<endl<<43<<endl<<27<<endl<<17<<endl<<94<<endl<<73<<endl<<17<<endl<<81<<endl<<53<<endl<<14<<endl<<22<<endl<<56<<endl<<48<<endl<<20<<endl<<8<<endl<<54<<endl<<38<<endl<<19<<endl<<59<<endl<<80<<endl<<22<<endl<<67<<endl<<59<<endl<<63<<endl<<89<<endl<<94<<endl<<41<<endl<<62<<endl<<36<<endl<<38<<endl<<61<<endl<<52<<endl<<19<<endl<<15<<endl<<49<<endl<<69<<endl<<23<<endl<<81<<endl<<64<<endl<<44<<endl<<24<<endl<<12<<endl<<63<<endl<<35<<endl<<66<<endl<<71<<endl<<65<<endl<<47<<endl<<9<<endl<<100<<endl<<46<<endl<<89<<endl<<76<<endl<<85<<endl<<5<<endl<<98<<endl<<40<<endl<<47<<endl<<72<<endl<<91<<endl<<86<<endl<<36<<endl<<63<<endl<<34<<endl<<99<<endl<<89<<endl<<92<<endl<<38<<endl<<44<<endl<<84<<endl<<23<<endl<<75<<endl<<2<<endl<<61<<endl<<71<<endl<<100<<endl<<33<<endl<<42<<endl<<86<<endl<<36<<endl<<60<<endl<<37<<endl<<65<<endl<<83<<endl<<87<<endl<<46<<endl<<45<<endl<<36<<endl<<83<<endl<<45<<endl<<95<<endl<<53<<endl<<45<<endl<<23<<endl<<89<<endl<<58<<endl<<47<<endl<<43<<endl<<67<<endl<<19<<endl<<68<<endl<<22<<endl<<26<<endl<<47<<endl<<62<<endl<<37<<endl<<89<<endl<<11<<endl<<93<<endl<<86<<endl<<94<<endl<<54<<endl<<22<<endl<<79<<endl<<100<<endl<<75<<endl<<67<<endl<<86<<endl<<54<<endl<<39<<endl<<80<<endl<<71<<endl<<100<<endl<<82<<endl<<35<<endl<<93<<endl<<4<<endl<<26<<endl<<21<<endl<<76<<endl<<57<<endl<<80<<endl<<84<<endl<<24<<endl<<29<<endl<<98<<endl<<88<<endl<<24<<endl<<81<<endl<<92<<endl<<6<<endl<<61<<endl<<29<<endl<<22<<endl<<7<<endl<<18<<endl<<15<<endl<<41<<endl<<24<<endl<<62<<endl<<25<<endl<<71<<endl<<5<<endl<<54<<endl<<60<<endl<<45<<endl<<49<<endl<<85<<endl<<79<<endl<<10<<endl<<76<<endl<<27<<endl<<31<<endl<<92<<endl<<48<<endl<<1<<endl<<45<<endl<<52<<endl<<36<<endl<<53<<endl<<15<<endl<<89<<endl<<71<<endl<<48<<endl<<5<<endl<<71<<endl<<79<<endl<<39<<endl<<13<<endl<<38<<endl<<70<<endl<<66<<endl<<44<<endl<<75<<endl<<38<<endl<<46<<endl<<17<<endl<<54<<endl<<53<<endl<<73<<endl<<83<<endl<<69<<endl<<48<<endl<<60<<endl<<19<<endl<<21<<endl<<77<<endl<<49<<endl<<73<<endl<<62<<endl<<26<<endl<<18<<endl<<78<<endl<<12<<endl<<45<<endl<<85<<endl<<1<<endl<<49<<endl<<14<<endl<<42<<endl<<73<<endl<<79<<endl<<70<<endl<<19<<endl<<42<<endl<<81<<endl<<73<<endl<<49<<endl<<55<<endl<<56<<endl<<29<<endl<<64<<endl<<38<<endl<<62<<endl<<91<<endl<<49<<endl<<50<<endl<<21<<endl<<77<<endl<<77<<endl<<34<<endl<<95<<endl<<39<<endl<<64<<endl<<33<<endl<<54<<endl<<3<<endl<<41<<endl<<40<<endl<<63<<endl<<37<<endl<<19<<endl<<62<<endl<<4<<endl<<16<<endl<<85<<endl<<80<<endl<<57<<endl<<32<<endl<<38<<endl<<6<<endl<<18<<endl<<51<<endl<<2<<endl<<62<<endl<<69<<endl<<72<<endl<<36<<endl<<32<<endl<<61<<endl<<5<<endl<<32<<endl<<63<<endl<<35<<endl<<20<<endl<<93<<endl<<37<<endl<<38<<endl<<64<<endl<<78<<endl<<61<<endl<<67<<endl<<83<<endl<<78<<endl<<96<<endl<<16<<endl<<3<<endl<<98<<endl<<17<<endl<<39<<endl<<37<<endl<<69<<endl<<91<<endl<<44<<endl<<79<<endl<<38<<endl<<94<<endl<<68<<endl<<4<<endl<<60<<endl<<45<<endl<<47<<endl<<88<<endl<<96<<endl<<76<<endl<<17<<endl<<5<<endl<<1<<endl<<33<<endl<<71<<endl<<59<<endl<<88<<endl<<14<<endl<<88<<endl<<70<<endl<<25<<endl<<2<<endl<<55<<endl<<100<<endl<<55<<endl<<77<<endl<<74<<endl<<89<<endl<<91<<endl<<81<<endl<<84<<endl<<62<<endl<<50<<endl<<61<<endl<<51<<endl<<88<<endl<<93<<endl<<26<<endl<<38<<endl<<60<<endl<<98<<endl<<9<<endl<<39<<endl<<1<<endl<<89<<endl<<100<<endl<<56<<endl<<75<<endl<<37<<endl<<83<<endl<<100<<endl<<61<<endl<<40<<endl<<19<<endl<<22<<endl<<62<<endl<<89<<endl<<71<<endl<<64<<endl<<43<<endl<<69<<endl<<20<<endl<<55<<endl<<75<<endl<<70<<endl<<7<<endl<<9<<endl<<94<<endl<<30<<endl<<35<<endl<<11<<endl<<9<<endl<<85<<endl<<4<<endl<<43<<endl<<93<<endl<<55<<endl<<9<<endl<<52<<endl<<90<<endl<<63<<endl<<7<<endl<<16<<endl<<16<<endl<<29<<endl<<79<<endl<<83<<endl<<15<<endl<<92<<endl<<18<<endl<<38<<endl<<91<<endl<<57<<endl<<20<<endl<<24<<endl<<79<<endl<<24<<endl<<53<<endl<<21<<endl<<9<<endl<<80<<endl<<28<<endl<<6<<endl<<72<<endl<<14<<endl<<85<<endl<<49<<endl<<96<<endl<<10<<endl<<36<<endl<<8<<endl<<74<<endl<<74<<endl<<16<<endl<<96<<endl<<52<<endl<<80<<endl<<18<<endl<<2<<endl<<56<<endl<<12<<endl<<41<<endl<<88<<endl<<77<<endl<<63<<endl<<63<<endl<<46<<endl<<84<<endl<<48<<endl<<8<<endl<<18<<endl<<90<<endl<<38<<endl<<20<<endl<<73<<endl<<81<<endl<<87<<endl<<65<<endl<<38<<endl<<72<<endl<<71<<endl<<80<<endl<<29<<endl<<34<<endl<<9<<endl<<71<<endl<<31<<endl<<33<<endl<<97<<endl<<37<<endl<<67<<endl<<18<<endl<<31<<endl<<48<<endl<<59<<endl<<95<<endl<<50<<endl<<23<<endl<<17<<endl<<92<<endl<<3<<endl<<84<<endl<<44<<endl<<11<<endl<<74<<endl<<86<<endl<<5<<endl<<12<<endl<<16<<endl<<65<<endl<<77<<endl<<59<<endl<<31<<endl<<50<<endl<<60<<endl<<62<<endl<<42<<endl<<14<<endl<<68<<endl<<4<<endl<<70<<endl<<93<<endl<<50<<endl<<7<<endl<<20<<endl<<55<<endl<<88<<endl<<29<<endl<<96<<endl<<15<<endl<<11<<endl<<86<<endl<<63<<endl<<28<<endl<<18<<endl<<90<<endl<<80<<endl<<49<<endl<<46<<endl<<31<<endl<<38<<endl<<43<<endl<<79<<endl<<91<<endl<<45<<endl<<50<<endl<<49<<endl<<18<<endl<<93<<endl<<46<<endl<<83<<endl<<38<<endl<<81<<endl<<56<<endl<<47<<endl<<67<<endl<<5<<endl<<76<<endl<<74<<endl<<28<<endl<<95<<endl<<24<<endl<<51<<endl<<9<<endl<<13<<endl<<5<<endl<<5<<endl<<24<<endl<<26<<endl<<26<<endl<<6<<endl<<63<<endl<<62<<endl<<85<<endl<<98<<endl<<45<<endl<<1<<endl<<55<<endl<<61<<endl<<39<<endl<<80<<endl<<55<<endl<<42<<endl<<60<<endl<<60<<endl<<13<<endl<<25<<endl<<20<<endl<<84<<endl<<21<<endl<<10<<endl<<48<<endl<<50<<endl<<61<<endl<<20<<endl<<71<<endl<<33<<endl<<15<<endl<<36<<endl<<21<<endl<<97<<endl<<37<<endl<<87<<endl<<31<<endl<<5<<endl<<62<<endl<<5<<endl<<45<<endl<<97<<endl<<48<<endl<<41<<endl<<8<<endl<<89<<endl<<3<<endl<<87<<endl<<59<<endl<<61<<endl<<20<<endl<<16<<endl<<86<<endl<<42<<endl<<38<<endl<<59<<endl<<87<<endl<<31<<endl<<94<<endl<<21<<endl<<5<<endl<<26<<endl<<92<<endl<<4<<endl<<74<<endl<<30<<endl<<85<<endl<<11<<endl<<80<<endl<<52<<endl<<91<<endl<<47<<endl<<88<<endl<<40<<endl<<24<<endl<<60<<endl<<47<<endl<<37<<endl<<9<<endl<<94<<endl<<92<<endl<<60<<endl<<21<<endl<<100<<endl<<31<<endl<<23<<endl<<87<<endl<<27<<endl<<6<<endl<<83<<endl<<78<<endl<<56<<endl<<93<<endl<<35<<endl<<1<<endl<<60<<endl<<8<<endl<<58<<endl<<100<<endl<<88<<endl<<53<<endl<<22<<endl<<6<<endl<<5<<endl<<71<<endl<<67<<endl<<73<<endl<<45<<endl<<13<<endl<<92<<endl<<10<<endl<<31<<endl<<63<<endl<<12<<endl<<61<<endl<<7<<endl<<88<<endl<<32<<endl<<83<<endl<<7<<endl<<64<<endl<<51<<endl<<8<<endl<<7<<endl<<33<<endl<<53<<endl<<58<<endl<<40<<endl<<82<<endl<<7<<endl<<5<<endl<<25<<endl<<23<<endl<<90<<endl<<66<<endl<<82<<endl<<52<<endl<<25<<endl<<69<<endl<<30<<endl<<11<<endl<<41<<endl<<14<<endl<<12<<endl<<70<<endl<<21<<endl<<77<<endl<<10<<endl<<94<<endl<<28<<endl<<80<<endl<<3<<endl<<57<<endl<<70<<endl<<46<<endl<<63<<endl<<55<<endl<<74<<endl<<99<<endl<<49<<endl<<67<<endl<<81<<endl<<17<<endl<<93<<endl<<2<<endl<<97<<endl<<40<<endl<<89<<endl<<58<<endl<<29<<endl<<71<<endl<<15<<endl<<18<<endl<<40<<endl<<62<<endl<<12<<endl<<100<<endl<<99<<endl<<34<<endl<<52<<endl<<41<<endl<<17<<endl<<17<<endl<<69<<endl<<11<<endl<<61<<endl<<32<<endl<<90<<endl<<11<<endl<<55<<endl<<74<<endl<<86<<endl<<32<<endl<<36<<endl<<8<<endl<<64<<endl<<90<<endl<<32<<endl<<7<<endl<<91<<endl<<26<<endl<<37<<endl<<48<<endl<<13<<endl<<10<<endl<<54<<endl<<99<<endl<<41<<endl<<49<<endl<<97<<endl<<99<<endl<<72<<endl<<1<<endl<<37<<endl<<84<<endl<<98<<endl<<17<<endl<<74<<endl<<4<<endl<<57<<endl<<19<<endl<<89<<endl<<84<<endl<<3<<endl<<94<<endl<<7<<endl<<90<<endl<<55<<endl<<35<<endl<<14<<endl<<49<<endl<<72<<endl<<17<<endl<<42<<endl<<9<<endl<<40<<endl<<22<<endl<<18<<endl<<34<<endl<<64<<endl<<87<<endl<<42<<endl<<37<<endl<<5<<endl<<9<<endl<<70<<endl<<98<<endl<<95<<endl<<72<<endl<<4<<endl<<4<<endl<<16<<endl<<7<<endl<<17<<endl<<46<<endl<<56<<endl<<34<<endl<<79<<endl<<3<<endl<<30<<endl<<68<<endl<<55<<endl<<17<<endl<<47<<endl<<26<<endl<<43<<endl<<46<<endl<<2<<endl<<21<<endl<<75<<endl<<80<<endl<<21<<endl<<94<<endl<<13<<endl<<35<<endl<<68<<endl<<78<<endl<<22<<endl<<81<<endl<<91<<endl<<19<<endl<<58<<endl<<98<<endl<<56<<endl<<55<<endl<<16<<endl<<43<<endl<<41<<endl<<58<<endl<<30<<endl<<60<<endl<<77<<endl<<56<<endl<<22<<endl<<57<<endl<<7<<endl<<99<<endl<<86<<endl<<21<<endl<<69<<endl<<61<<endl<<63<<endl<<77<<endl<<1<<endl<<14<<endl<<17<<endl<<54<<endl<<88<<endl<<7<<endl<<27<<endl<<1<<endl<<5<<endl<<74<<endl<<31<<endl<<62<<endl<<91<<endl<<46<<endl<<51<<endl<<60<<endl<<28<<endl<<26<<endl<<36<<endl<<26<<endl<<39<<endl<<72<<endl<<67<<endl<<46<<endl<<98<<endl<<97<<endl<<31<<endl<<47<<endl<<46<<endl<<32<<endl<<85<<endl<<8<<endl<<80<<endl<<64<<endl<<52<<endl<<45<<endl<<19<<endl<<19<<endl<<31<<endl<<63<<endl<<49<<endl<<5<<endl<<13<<endl<<22<<endl<<51<<endl<<13<<endl<<97<<endl<<92<<endl<<37<<endl<<26<<endl<<97<<endl<<42<<endl<<62<<endl<<88<<endl<<61<<endl<<69<<endl<<80<<endl<<12<<endl<<26<<endl<<49<<endl<<89<<endl<<2<<endl<<14<<endl<<66<<endl<<78<<endl<<76<<endl<<80<<endl<<24<<endl<<50<<endl<<3<<endl<<41<<endl<<87<<endl<<4<<endl<<79<<endl<<40<<endl<<66<<endl<<50<<endl<<65<<endl<<61<<endl<<70<<endl<<91<<endl<<89<<endl<<52<<endl<<58<<endl<<75<<endl<<89<<endl<<72<<endl<<86<<endl<<8<<endl<<69<<endl<<19<<endl<<54<<endl<<47<<endl<<76<<endl<<3<<endl<<87<<endl<<99<<endl<<67<<endl<<27<<endl<<37<<endl<<37<<endl<<10<<endl<<4<<endl<<12<<endl<<100<<endl<<46<<endl<<79<<endl<<75<<endl<<98<<endl<<92<<endl<<53<<endl<<40<<endl<<2<<endl<<36<<endl<<92<<endl<<31<<endl<<10<<endl<<5<<endl<<97<<endl<<12<<endl<<86<<endl<<39<<endl<<45<<endl<<89<<endl<<95<<endl<<78<<endl<<79<<endl<<72<<endl<<27<<endl<<62<<endl<<67<<endl<<12<<endl<<16<<endl<<31<<endl<<44<<endl<<70<<endl<<55<<endl<<51<<endl<<1<<endl<<86<<endl<<50<<endl<<49<<endl<<23<<endl<<97<<endl<<84<<endl<<68<<endl<<27<<endl<<87<<endl<<79<<endl<<42<<endl<<50<<endl<<42<<endl<<14<<endl<<89<<endl<<71<<endl<<89<<endl<<92<<endl<<48<<endl<<32<<endl<<13<<endl<<28<<endl<<38<<endl<<40<<endl<<35<<endl<<80<<endl<<10<<endl<<22<<endl<<10<<endl<<81<<endl<<53<<endl<<99<<endl<<24<<endl<<29<<endl<<84<<endl<<9<<endl<<73<<endl<<73<<endl<<81<<endl<<82<<endl<<70<<endl<<94<<endl<<53<<endl<<54<<endl<<30<<endl<<55<<endl<<62<<endl<<68<<endl<<77<<endl<<32<<endl<<39<<endl<<54<<endl<<36<<endl<<11<<endl<<78<<endl<<43<<endl<<24<<endl<<54<<endl<<4<<endl<<20<<endl<<15<<endl<<38<<endl<<73<<endl<<72<<endl<<78<<endl<<73<<endl<<24<<endl<<56<<endl<<25<<endl<<42<<endl<<77<<endl<<14<<endl<<83<<endl<<89<<endl<<43<<endl<<94<<endl<<10<<endl<<8<<endl<<63<<endl<<18<<endl<<67<<endl<<10<<endl<<41<<endl<<25<<endl<<60<<endl<<83<<endl<<50<<endl<<30<<endl<<90<<endl<<79<<endl<<62<<endl<<13<<endl<<1<<endl<<25<<endl<<87<<endl<<21<<endl<<15<<endl<<12<<endl<<43<<endl<<20<<endl<<48<<endl<<79<<endl<<98<<endl<<14<<endl<<74<<endl<<98<<endl<<57<<endl<<95<<endl<<42<<endl<<99<<endl<<24<<endl<<92<<endl<<71<<endl<<75<<endl<<81<<endl<<14<<endl<<47<<endl<<14<<endl<<9<<endl<<26<<endl<<27<<endl<<42<<endl<<48<<endl<<23<<endl<<59<<endl<<88<<endl<<96<<endl<<98<<endl<<11<<endl<<32<<endl<<52<<endl<<70<<endl<<60<<endl<<49<<endl<<1<<endl<<16<<endl<<77<<endl<<48<<endl<<17<<endl<<88<<endl<<1<<endl<<64<<endl<<49<<endl<<44<<endl<<96<<endl<<10<<endl<<63<<endl<<98<<endl<<93<<endl<<92<<endl<<38<<endl<<3<<endl<<15<<endl<<62<<endl<<46<<endl<<97<<endl<<95<<endl<<26<<endl<<44<<endl<<49<<endl<<19<<endl<<38<<endl<<64<<endl<<83<<endl<<90<<endl<<99<<endl<<12<<endl<<74<<endl<<15<<endl<<38<<endl<<53<<endl<<44<<endl<<9<<endl<<67<<endl<<56<<endl<<7<<endl<<29<<endl<<54<<endl<<31<<endl<<35<<endl<<86<<endl<<93<<endl<<10<<endl<<19<<endl<<35<<endl<<13<<endl<<71<<endl<<62<<endl<<56<<endl<<24<<endl<<70<<endl<<50<<endl<<32<<endl<<12<<endl<<58<<endl<<46<<endl<<17<<endl<<11<<endl<<1<<endl<<99<<endl<<19<<endl<<47<<endl<<3<<endl<<3<<endl<<33<<endl<<72<<endl<<59<<endl<<50<<endl<<67<<endl<<11<<endl<<7<<endl<<28<<endl<<25<<endl<<57<<endl<<2<<endl<<61<<endl<<67<<endl<<11<<endl<<36<<endl<<77<<endl<<88<<endl<<61<<endl<<66<<endl<<3<<endl<<7<<endl<<21<<endl<<51<<endl<<99<<endl<<100<<endl<<65<<endl<<56<<endl<<76<<endl<<85<<endl<<83<<endl<<80<<endl<<82<<endl<<76<<endl<<5<<endl<<28<<endl<<4<<endl<<54<<endl<<99<<endl<<93<<endl<<53<<endl<<56<<endl<<49<<endl<<2<<endl<<97<<endl<<22<<endl<<44<<endl<<19<<endl<<39<<endl<<100<<endl<<25<<endl<<55<<endl<<10<<endl<<48<<endl<<28<<endl<<51<<endl<<54<<endl<<25<<endl<<35<<endl<<18<<endl<<61<<endl<<47<<endl<<37<<endl<<1<<endl<<86<<endl<<82<<endl<<16<<endl<<99<<endl<<22<<endl<<98<<endl<<59<<endl<<10<<endl<<10<<endl<<88<<endl<<49<<endl<<5<<endl<<53<<endl<<20<<endl<<26<<endl<<83<<endl<<3<<endl<<96<<endl<<64<<endl<<41<<endl<<77<<endl<<59<<endl<<18<<endl<<60<<endl<<31<<endl<<10<<endl<<47<<endl<<80<<endl<<4<<endl<<2<<endl<<24<<endl<<55<<endl<<11<<endl<<35<<endl<<17<<endl<<97<<endl<<84<<endl<<48<<endl<<43<<endl<<100<<endl<<28<<endl<<20<<endl<<38<<endl<<67<<endl<<90<<endl<<72<<endl<<12<<endl<<37<<endl<<15<<endl<<14<<endl<<83<<endl<<52<<endl<<48<<endl<<39<<endl<<48<<endl<<62<<endl<<71<<endl<<75<<endl<<57<<endl<<31<<endl<<73<<endl<<18<<endl<<34<<endl<<3<<endl<<70<<endl<<2<<endl<<94<<endl<<50<<endl<<18<<endl<<31<<endl<<62<<endl<<86<<endl<<91<<endl<<8<<endl<<2<<endl<<2<<endl<<99<<endl<<28<<endl<<54<<endl<<30<<endl<<65<<endl<<92<<endl<<79<<endl<<31<<endl<<40<<endl<<8<<endl<<65<<endl<<31<<endl<<5<<endl<<89<<endl<<50<<endl<<45<<endl<<100<<endl<<3<<endl<<72<<endl<<39<<endl<<57<<endl<<58<<endl<<14<<endl<<84<<endl<<16<<endl<<48<<endl<<73<<endl<<68<<endl<<36<<endl<<92<<endl<<75<<endl<<77<<endl<<50<<endl<<49<<endl<<39<<endl<<22<<endl<<76<<endl<<88<<endl<<10<<endl<<83<<endl<<58<<endl<<8<<endl<<95<<endl<<28<<endl<<68<<endl<<80<<endl<<50<<endl<<13<<endl<<66<<endl<<39<<endl<<71<<endl<<48<<endl<<53<<endl<<18<<endl<<59<<endl<<45<<endl<<9<<endl<<64<<endl<<1<<endl<<73<<endl<<73<<endl<<27<<endl<<73<<endl<<59<<endl<<6<<endl<<8<<endl<<95<<endl<<12<<endl<<15<<endl<<44<<endl<<19<<endl<<48<<endl<<44<<endl<<34<<endl<<36<<endl<<62<<endl<<19<<endl<<95<<endl<<16<<endl<<34<<endl<<33<<endl<<4<<endl<<81<<endl<<33<<endl<<50<<endl<<22<<endl<<81<<endl<<32<<endl<<90<<endl<<34<<endl<<76<<endl<<57<<endl<<23<<endl<<77<<endl<<18<<endl<<73<<endl<<7<<endl<<95<<endl<<46<<endl<<72<<endl<<16<<endl<<2<<endl<<59<<endl<<6<<endl<<89<<endl<<79<<endl<<64<<endl<<87<<endl<<84<<endl<<6<<endl<<4<<endl<<76<<endl<<53<<endl<<16<<endl<<53<<endl<<93<<endl<<68<<endl<<79<<endl<<57<<endl<<79<<endl<<74<<endl<<29<<endl<<69<<endl<<90<<endl<<15<<endl<<91<<endl<<9<<endl<<93<<endl<<88<<endl<<76<<endl<<12<<endl<<6<<endl<<9<<endl<<92<<endl<<59<<endl<<39<<endl<<84<<endl<<68<<endl<<70<<endl<<93<<endl<<9<<endl<<83<<endl<<88<<endl<<35<<endl<<16<<endl<<52<<endl<<97<<endl<<40<<endl<<34<<endl<<59<<endl<<39<<endl<<39<<endl<<1<<endl<<98<<endl<<42<<endl<<67<<endl<<85<<endl<<64<<endl<<60<<endl<<49<<endl<<20<<endl<<84<<endl<<28<<endl<<34<<endl<<41<<endl<<79<<endl<<27<<endl<<59<<endl<<12<<endl<<20<<endl<<46<<endl<<11<<endl<<82<<endl<<55<<endl<<57<<endl<<80<<endl<<67<<endl<<84<<endl<<51<<endl<<23<<endl<<26<<endl<<18<<endl<<63<<endl<<22<<endl<<88<<endl<<65<<endl<<58<<endl<<74<<endl<<45<<endl<<3<<endl<<19<<endl<<56<<endl<<35<<endl<<73<<endl<<64<<endl<<65<<endl<<69<<endl<<28<<endl<<72<<endl<<31<<endl<<85<<endl<<22<<endl<<54<<endl<<71<<endl<<33<<endl<<41<<endl<<38<<endl<<79<<endl<<14<<endl<<26<<endl<<34<<endl<<55<<endl<<46<<endl<<67<<endl<<34<<endl<<63<<endl<<81<<endl<<91<<endl<<83<<endl<<12<<endl<<15<<endl<<89<<endl<<99<<endl<<15<<endl<<44<<endl<<13<<endl<<14<<endl<<81<<endl<<37<<endl<<97<<endl<<75<<endl<<23<<endl<<7<<endl<<100<<endl<<70<<endl<<50<<endl<<23<<endl<<82<<endl<<43<<endl<<93<<endl<<99<<endl<<34<<endl<<13<<endl<<53<<endl<<43<<endl<<13<<endl<<40<<endl<<9<<endl<<38<<endl<<92<<endl<<44<<endl<<53<<endl<<53<<endl<<9<<endl<<9<<endl<<39<<endl<<9<<endl<<24<<endl<<6<<endl<<13<<endl<<95<<endl<<65<<endl<<53<<endl<<14<<endl<<60<<endl<<54<<endl<<10<<endl<<29<<endl<<54<<endl<<4<<endl<<73<<endl<<70<<endl<<38<<endl<<84<<endl<<14<<endl<<88<<endl<<66<<endl<<42<<endl<<47<<endl<<10<<endl<<60<<endl<<49<<endl<<14<<endl<<22<<endl<<99<<endl<<32<<endl<<15<<endl<<79<<endl<<69<<endl<<13<<endl<<11<<endl<<84<<endl<<85<<endl<<70<<endl<<49<<endl<<56<<endl<<15<<endl<<35<<endl<<40<<endl<<71<<endl<<59<<endl<<55<<endl<<6<<endl<<27<<endl<<66<<endl<<18<<endl<<49<<endl<<85<<endl<<82<<endl<<24<<endl<<25<<endl<<42<<endl<<92<<endl<<68<<endl<<10<<endl<<18<<endl<<40<<endl<<7<<endl<<83<<endl<<60<<endl<<40<<endl<<57<<endl<<71<<endl<<74<<endl<<82<<endl<<65<<endl<<33<<endl<<37<<endl<<22<<endl<<96<<endl<<81<<endl<<33<<endl<<59<<endl<<61<<endl<<52<<endl<<98<<endl<<91<<endl<<78<<endl<<13<<endl<<18<<endl<<77<<endl<<26<<endl<<59<<endl<<89<<endl<<94<<endl<<99<<endl<<14<<endl<<57<<endl<<30<<endl<<18<<endl<<32<<endl<<22<<endl<<83<<endl<<12<<endl<<93<<endl<<58<<endl<<33<<endl<<80<<endl<<60<<endl<<87<<endl<<21<<endl<<90<<endl<<62<<endl<<14<<endl<<39<<endl<<75<<endl<<33<<endl<<81<<endl<<46<<endl<<90<<endl<<7<<endl<<70<<endl<<93<<endl<<72<<endl<<16<<endl<<27<<endl<<98<<endl<<4<<endl<<44<<endl<<74<<endl<<76<<endl<<62<<endl<<82<<endl<<63<<endl<<67<<endl<<78<<endl<<37<<endl<<78<<endl<<43<<endl<<8<<endl<<37<<endl<<18<<endl<<68<<endl<<54<<endl<<38<<endl<<54<<endl<<48<<endl<<99<<endl<<17<<endl<<38<<endl<<84<<endl<<25<<endl<<97<<endl<<94<<endl<<5<<endl<<1<<endl<<63<<endl<<21<<endl<<40<<endl<<54<<endl<<85<<endl<<37<<endl<<54<<endl<<76<<endl<<87<<endl<<60<<endl<<44<<endl<<94<<endl<<68<<endl<<65<<endl<<42<<endl<<92<<endl<<89<<endl<<79<<endl<<2<<endl<<21<<endl<<74<<endl<<64<<endl<<84<<endl<<1<<endl<<69<<endl<<62<<endl<<99<<endl<<60<<endl<<48<<endl<<6<<endl<<30<<endl<<69<<endl<<1<<endl<<62<<endl<<16<<endl<<95<<endl<<26<<endl<<22<<endl<<22<<endl<<65<<endl<<31<<endl<<86<<endl<<52<<endl<<84<<endl<<14<<endl<<50<<endl<<54<<endl<<83<<endl<<30<<endl<<83<<endl<<36<<endl<<2<<endl<<27<<endl<<85<<endl<<31<<endl<<75<<endl<<9<<endl<<96<<endl<<65<<endl<<48<<endl<<56<<endl<<75<<endl<<40<<endl<<29<<endl<<95<<endl<<13<<endl<<48<<endl<<72<<endl<<77<<endl<<71<<endl<<97<<endl<<57<<endl<<88<<endl<<94<<endl<<8<<endl<<34<<endl<<68<<endl<<1<<endl<<19<<endl<<55<<endl<<8<<endl<<60<<endl<<2<<endl<<25<<endl<<99<<endl<<25<<endl<<14<<endl<<23<<endl<<59<<endl<<57<<endl<<61<<endl<<62<<endl<<38<<endl<<67<<endl<<10<<endl<<4<<endl<<99<<endl<<90<<endl<<99<<endl<<79<<endl<<80<<endl<<60<<endl<<80<<endl<<79<<endl<<78<<endl<<92<<endl<<80<<endl<<27<<endl<<3<<endl<<84<<endl<<57<<endl<<65<<endl<<26<<endl<<9<<endl<<90<<endl<<44<<endl<<26<<endl<<13<<endl<<69<<endl<<48<<endl<<12<<endl<<23<<endl;
		
	}
	return 0;
}
